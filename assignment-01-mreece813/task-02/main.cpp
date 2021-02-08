#include <iostream>
using namespace std;

int main()
{
    double mass;
    double energy;
    double c = 3*10e+7;
    cout << "What is your mass?" << endl;
    cin >> mass;
    energy = (mass*(c*c));
    cout << "" << energy << endl;
    cout << endl;
    return 0;
}