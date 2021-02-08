#include <iostream>
using namespace std;

int main()
{
    cout<< "What is your velocity, acceleration, and time elapsed?" << "\n";
    double v= 0.0;
    double a= 0.0;
    double t= 0.0;

    cin >> v >> a >> t;

    double d = v * t + 0.5 * a * t * t;
    cout << d << "\n";
}