#include <iostream>
#include <string>
#include <fmt/format.h>
#include <fstream>
using namespace std;

double f (double a) 
{
    return 1.22 * a * a - 37.9 * a + 8.1;
}

int main() 
{
    ofstream csv("data.csv");
    csv << "x,f(x)" << endl;
    for (double x=0; x < 50; x++) 
    {
        csv << fmt::format("{0:.2f},{1:.2f}", x, f(x) )  << endl;;
    }

}