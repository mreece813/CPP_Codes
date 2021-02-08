CXX:=g++
STD:=-std=c++17
CFLAGS:=-Wall -Werror -Wextra -Weffc++ -pedantic
DEFINITIONS:= -DFMT_HEADER_ONLY
DEBUG_FLAGS:=-O3

PYTHON:=python3

SRC:=$(wildcard src/*.cpp)
INC:=$(wildcard include/*.h) $(wildcard include/ruc-sci-comp/*.hpp)
OBJ:=$(SRC:src/%.cpp=obj/%.o)
DEP:=$(SRC:src/%.cpp=dep/%.d)
TRGT:=main.exe

ifeq ($(SRC),)
$(error No source files found, there is nothing to build!)
endif

INCLUDES:=-isystem ../include -isystem include

PYVERSION:=$(shell $(PYTHON) --version)
PY8_REGEX:=^Python [0-9]+\.8\.[0-9]+$

PYTHON_INCLUDES:=$(shell $(PYTHON)-config --includes)
PYTHON_LIB_DIR:=$(shell $(PYTHON)-config --prefix)/lib
ifeq ($(shell echo ${PYVERSION} | egrep "${PY8_REGEX}"),)
PYTHON_LIBS:=$(shell $(PYTHON)-config --libs)
else
PYTHON_LIBS:=$(shell $(PYTHON)-config --libs --embed)
endif
PYTHON_LD_FLAGS:=-Wl,-rpath,$(PYTHON_LIB_DIR) -L$(PYTHON_LIB_DIR) $(PYTHON_LIBS)

HTML:=defense.html

$(TRGT): setup $(OBJ)
	$(CXX) $(OBJ) $(PYTHON_LD_FLAGS) -o $@

setup:
	@mkdir -p obj
	@mkdir -p dep

-include $(DEP)

obj/%.o: src/%.cpp $(INC)
	$(CXX) $(STD) $(DEBUG_FLAGS) $(CFLAGS) $(DEFINITIONS) $(INCLUDES) $(PYTHON_INCLUDES) -MF dep/$(<:src/%.cpp=%.d) -MMD -c $< -o $@

clean:
	rm -rf obj dep $(TRGT) test_output __pycache__ $(HTML) 

test: $(TEST) $(TRGT)
	contest contest.yaml

move-plot:
	@mkdir -p ~/public_html
	@chmod 755 ~/public_html
	@cp $(HTML) ~/public_html
	@chmod 755 ~/public_html/$(HTML)

clamshell:
	@cp -R ~/malen/include .
	@cp -R ~/malen-bokeh/include .
	@cp -R ~/malen-bokeh/malen/ .
	@cp -R ~/fmt/include .
	@cp -R ~/json/include .

.PHONY:all setup clean test move-plot clamshell
