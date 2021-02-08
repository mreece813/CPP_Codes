#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

int main()
{
    std::uniform_real_distribution<double> dis(-M_PI, M_PI);
    std::mt19937_64 eng(9001);
    std::vector<double> angles;
    angles.reserve(10);

    for (int i = 0; i < 10; ++i)
    {
        angles.push_back(dis(eng));
    }

    std::sort(angles.begin(), angles.end());

    //-------------------------------------------------------------------------
    // this code below is fine, do not modify it!
    std::copy(std::begin(angles), std::end(angles), std::ostream_iterator<double>(std::cout, "\n"));
    std::cout << std::flush;
}