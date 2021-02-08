#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
using namespace std;

int main()
{
    vector<double> data(100);
    mt19937_64 eng(1337);
    normal_distribution<double> dis(0.5, 1.0);
    generate(begin(data), end(data), [&](){return dis(eng);});

    // -------------------------------------------------------------------------
    // Use std::accumulate to sum all of the numbers in the vector!
    // -------------------------------------------------------------------------

    double sum = accumulate(begin(data), end(data), 0.0);

    // -------------------------------------------------------------------------
    cout << sum << endl;
}
