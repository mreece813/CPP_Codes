#include <iostream>
#include <string>
using namespace std;

int main()
{
    string temp; //Creating variable for Temperature
    char letter; //Variable to save the last letter
    double c; //Variable for Celsius
    double f; //Variable for Fahrenheit
    cout << "What is your temperature?" << endl;
    cin >> temp;
    letter = temp.back();
    if (letter == 'f')
    {
        f = stod(temp);
        c = (f - 32.0)*5.0 / 9.0;
        cout << c << "c" << endl;
    }
    else
    {
        c = stod(temp);
        f = c*9.0/5.0 + 32.0;
        cout <<  f << "f" << endl;
    }
}