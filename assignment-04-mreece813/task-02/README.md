# task-02

This program will write a basic CSV file.

### Clamshell Users

Before starting this task, run the following command in the task folder.

```shell
make clamshell
```

This will add `fmt` to your task, assuming you downloaded it as specified in the main `README.md` for the assignment.

## Task

This task is relatively straightforward - we want to start learning how to use `fmt` for formatting strings. Throughout this program we will create strings using `fmt::format` and then simply print them out. Start by creating a new file `main.cpp` here in the task directory. **In addition** to the headers from `task-01`, We will need the following header:

* `#include <fstream>`

Do not forget `using namespace std;`! `fstream` will give us access to tools to create a file and write to it. We want to write a program that creates a CSV file. We will be filling it with useless data, but it will still be a CSV file. We will create a sort of algebraic "function table" - the first column will be values of "x", and the other column will be a "y" value generated by some function.

Forward declare a function named `f` that returns a `double` and accepts a single `double` as a parameter. With that forward declaration done, let's start our main function. The very first thing we need to do is create a `ofstream` and open the file `"data.csv"`. This needs to be an `ofstream` because we are writing data *out* of our program.

Once we have our file opened, we want to add a header to the file; our header is simple just `"x,f(x)"`. The first column is `x` and the second column is the result of `f(x)` for each value `x`. Follow the header with an `endl`.

We now need a for-loops that iterates a `double` named `x` from `0.0` to `50.0` (not including `50.0`!). Within the for-loop we need to construct a string using `fmt::format` that simply consists of the values `x` and the output of `f(x)` separated by a comma. We can write this string to our `ofstream`, followed by `endl`. Our `main` function is now complete, let's now write our `f` function.

This function takes in a `double`, and should just return the result of the equation:

```
1.22 * x * x - 37.9 * x + 8.1
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

Your program will not appear to do anything, but if it worked properly, you should now see a file named `data.csv`! You can open it, and you should see the header, followed by 50 rows of numbers.

## Testing

Try testing the program with:

```shell
make test
```
