# task-01

This program will use `fmt` to format some strings.

### Clamshell Users

Before starting this task, run the following command in the task folder.

```shell
make clamshell
```

This will add `fmt` to your task, assuming you downloaded it as specified in the main `README.md` for the assignment.

## Task

This task is relatively straightforward - we want to start learning how to use `fmt` for formatting strings. Throughout this program we will create strings using `fmt::format` and then simply print them out. Start by creating a new file `main.cpp` here in the task directory. We will need the following headers:

* `#include <iostream>`
* `#include <string>`
* `#include <fmt/format.h>`

Do not forget `using namespace std;`! `iostream` and `string` are included for the basics, and `fmt/format.h` to get access to the `fmt` library.

The first formatting we want to do is create a string with the blueprint `"It's {0} to go alone! Take this."`. Create a string using `fmt::format` and this blueprint, passing in `"dangerous"` as the formattable input.

The second set of formatting we want to do is print out a double with various levels of precision; use the following blueprint as a basis from which you can modify: `"22.0/7.0 = {0}"`. Create a `double` and initialize it to `22.0/7.0`. On separate lines, we want to print this double with the following number of decimal places:

* 0
* 3
* 7

You will need to modify the content of the curly braces in the blueprint in order to control the precision. You can print the resulting string from `fmt::format` directly, or create new strings to print.

Lastly, we want to print the three numbers `3.14`, `1.414`, and `9.81` separated by commas, each with 5 decimals of precision. Come up with the blueprint yourself and then you can print the resulting string from `fmt::format` directly, or create a new string to print. For this formatting, the resulting string should look like this:

```text
3.14000,1.41400,9.81000
```

Trying building your program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe
```

It will print all of the formatted strings!

```shell
~/home/turtleshell/cpp-assignment-04-amortization-schedule/task-01# ./main.exe 
It's dangerous to go alone! Take this.
22.0/7.0 = 3
22.0/7.0 = 3.143
22.0/7.0 = 3.1428571
3.14000,1.41400,9.81000
```

## Testing

Try testing the program with:

```shell
make test
```
