#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <fmt/format.h>
using namespace std;

int main() 
{
    cout << "Enter a file:" << endl;
    string file_name;
    cin >> file_name;
    ifstream loan_details(file_name);
    if (!loan_details)
    {
    cerr << "Could not load " << file_name << endl;
    return 1;
    }
    double loan_amount = 0.0;
    double interest_rate = 0.0;
    int loan_term = 0;
    loan_details >> loan_amount;
    loan_details >> interest_rate;
    loan_details >> loan_term;
    interest_rate = interest_rate / 1200.0;
    loan_term = loan_term * 12;
    double monthly_payment = loan_amount * interest_rate * pow((1 + interest_rate), loan_term) / (pow((1 + interest_rate), loan_term) -1);
    ofstream schedule("loan_schedule.csv");
    schedule << "payment,amount,interest,principle,balance" << endl;
    for (int m=1; m <= loan_term; m++)
    {
        double accrued_interest = loan_amount * interest_rate;
        double principle_payment = monthly_payment - accrued_interest;
        loan_amount = loan_amount - principle_payment;
        schedule << fmt::format("{0},{1:.2f},{2:.2f},{3:.2f},{4:.2f}", m,monthly_payment, accrued_interest, principle_payment, loan_amount) << endl;
    }
}