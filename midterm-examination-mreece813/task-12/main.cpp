#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter an angle:" << endl;
    double d;
    cin >> d;
    double r;
    r = d * M_PI / 180.0;
    cout << cos(r) << endl;
}