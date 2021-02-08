#include <cmath>
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// Write a function that computes how many time a wheel has rotated using the
// distance it traveled while rolling. The equation is given as:
//
// n = d / (2.0 * pi * r)
//
// Here we have the following:
//  * n = number of revolutions
//  * d = distance traveled
//  * r = radius of the wheel
//
// Your function should take two doubles (distance, radius) as arguments and
// return a double. The function should be named revolutions.
//
// NOTE: use M_PI for pi in your code.
// -----------------------------------------------------------------------------
double revolutions(double distance, double radius)
{
    return distance / (2.0 * M_PI * radius);
}


// -----------------------------------------------------------------------------

int main()
{
    cout << revolutions(1.0, 1.0) << endl;
    cout << revolutions(M_PI, 0.5) << endl;
    cout << revolutions(M_PI_2, 0.5) << endl;
    cout << revolutions(100.0, 0.1) << endl;
}
