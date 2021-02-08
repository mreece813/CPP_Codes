#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    cout << "What is your hypotenuse length and angle?" << "\n";
    double length = 0.0;
    double angle = 0.0;

    cin >> length >> angle;

    double theta = angle * M_PI / 180.0;
    double x = length * cos(theta);
    double y = length * sin(theta);

    cout << x << "\n";
    cout << y << "\n";

}