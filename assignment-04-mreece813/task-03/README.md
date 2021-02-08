# task-03

For this task we are going to write a calculator for loan scheduling.

### Clamshell Users

Before starting this task, run the following command in the task folder.

```shell
make clamshell
```

This will move the `fmt` library into place.

## Task

Whenever someone takes out a loan an amortization schedule is produced. This schedule includes a fixed payment amount per pay period with the goal of paying off the loan by the end of the designated loan term. With a principle loan amount, loan term, and interest rate we can determine the payment schedule. To do so we can compute the montly payment amount and then split that payment into interest and principle payments.

We can break down the entire process as follows:

```text
01)  Acquire information about the loan
02)  Compute the monthly payment amount
03)  Determine the split between interest and principle payments
04)  Update the loan amount
05)  Update the schedule
```

Here, steps 3, 4 and 5 are in some loop that we repeat for every payment in our schedule. Begin by creating a new file named `main.cpp` here in the task folder. You need the following headers:

* `#include <cmath>`
* `#include <fstream>`
* `#include <iostream>`
* `#include <string>`
* `#include <fmt/format.h>`

Do not forget `using namespace std;`! We have added `cmath` for its `pow` function and `fstream` for managing files. Let's start our `main` function by asking the user to input the name of a configuration file. This configuration file will contain details about a loan. When writing our code we want the program to very specifically request the following:

```text
Enter a file:
```

The spelling, capitalization, and punctuation are all very specific, so copy and paste that text as your output! Create a `string` named `file_name` and use `cin` to read a value into it.

With a file name available we can use `ifstream` to open it. Create a new `ifstream` variable named `loan_details`. We want to make sure we have appropriately opened the file for reading, so we can use the following code to check if its usable:

```cpp
if (!loan_details)
{
    cerr << "Could not load " << file_name << endl;
    return 1;
}
```

Here `cerr` is the sibling of `cout` that is used specifically for writing errors. Note that we also say `return 1`; this is a status code we can send to our operating system to indicate a failure (0 means no failure, anything else means failure!). Copy and paste that block of code right after creating the `ifstream`.

Our `loan_details` file should contain three values: the loan amount, the annual interest rate (as a percent), and the term of the loan in years. So for example, it could specify a $130,000 loan at 3.25 APR over 30 years. We need to read this data into our program, and so we need three new variables:

```cpp
double loan_amount = 0.0;
double interest_rate = 0.0;
int loan_term = 0;
```

With these variable now available, we can read them from `loan_details` using the `>>` operator (just as if it were `cin`). Once we read them, we need to adjust them to fit the algorithm we plan on using. This means converting `interest_rate` to a *monthly percentage as a fraction* (i.e. divide it by 1200.0) and the loan term needs to be in months (i.e. multiply by 12).

The benefit of an amortized loan schedule is that every single payment you make is the *same* amount. We can calculate this fixed amount using the following formula:

```text
A = P * r * (1 + r)^n / ((1 + r)^n - 1)
```

*Note that the above is not valid C++, do not attempt to use it as is!*

Here, `A` is the *monthly payment amount*, `P` is the *principle loan amount*, `r` is the *interest rate*, and `n` is the *total number of payments made (i.e. total months of the loan)*.

We should create a new variable for this monthly payment amount:

```c++
double monthly_payment = // set me equal to the computation above!
```

In order to perform exponents like we have in our formula above, we can make use of the `std::pow` function. Here are some examples of how we can use it (don't actually put these in your assignment, __these are just examples__):

```c++
double y = pow(10.0, 2.0);  // y is 100.0
double z = pow(11.2, 3.14); // z is approximately 1970.3555
```

In our formula for `A` above, make use of the `pow` function to handle the exponents and calculate `monthly_payment`. This is the most tedious part of the assignment, so take your time with it and make sure you have the formula correct!

Once you have the `monthly_payment` computed we can actually begin with creating our amortization schedule. Create a `ofstream` variable named `schedule` to open the file `"loan_schedule.csv"`. This is the file in which we will write all of the data. We need to give the data a header, so let's do the following:

```cpp
schedule << "payment,amount,interest,principle,balance" << endl;
```

This will write the column names to the file first. With the header written we can move to generate and write the rest of the data.

Start a for-loop that iterates an `int` named `m` from `1` to `loan_term` (including `loan_term`, so use `<=`). We will use each iteration of the loop to represent each month of the payment plan, where `m` is the number of that month.

For each month we want to inspect the loan balance and use the interest rate to figure out how much interest has been accrued. This is done by multiplying the `loan_amount` by `interest_rate` and saving the result in a new `double` named `accrued_interest`.

We can then take the accrued interest and subtract it from the monthly payment to get the principle payment amount. Save this new values as a `double` named `principle_payment`.

And finally, once we have the principle payment amount we can *update* the `loan_amount` by subtracting `principle_payment` from it.

With all of this information: `m`, `monthly_payment`, `accrued_interest`, `principle_payment`, and `loan_amount` we can use `fmt::format` to create a string to write to our file. Create a format blueprint that separates these values by commas. All but `m` should be printed with just 2 decimal places.

For example, a record in the CSV might looks like:

```text
1,794.82,500.00,294.82,29705.18
```

Where:

* `m                 ` = 1
* `monthly_payment   ` = 794.82
* `accrued_interest  ` = 500.00
* `principle_payment ` = 294.82
* `loan_amount       ` = 29705.18

Once you have the record written to the file (followed by `endl`), your loop is done and so is your amortization calculator!

Trying building your program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe
```

It will ask you `"Enter a file:"`, enter `data/loan_details.txt`. If the program works then it will print nothing else, and will have created a new file named `"loan_schedule.csv"`.

```shell
~/home/turtleshell/cpp-assignment-03-statistics-simple/task-03# ./main.exe 
Enter a file:
data/loan_details.txt
```

## Testing

Try testing the program with:

```shell
make test
```
