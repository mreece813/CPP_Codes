#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a radius:" << endl;
    double r;
    cin >> r;
    double v,a;
    v = 4 * M_PI * (r*r*r) / 3;
    a = 4 * M_PI * (r*r);
    cout << v << endl;
    cout << a << endl;
}