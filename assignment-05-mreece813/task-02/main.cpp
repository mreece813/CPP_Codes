#include <iostream>
#include <random>
#include <vector>
#include <fmt/format.h>
#include <ruc-sci-comp/plot.hpp>
#include <cmath>
using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cerr << "Invalid number of arguments - you must specify how many random points to generate!" << endl;
        return 1;
    }
    auto max_count = stoi(argv[1]);
    if (max_count < 1)
    {
       cerr << "Invalid number of points specified - you must provide a positive integer!" << endl;
        return 2;
    }
    mt19937_64 eng(1337);
    uniform_real_distribution<double> dis(-1.0,1.0);
    vector<double> xs(max_count);
    vector<double> ys(max_count);
    int count = 0;
    for (int i=0; i<max_count; i++)
    {
        double x = dis(eng);
        double y = dis(eng);
        xs.push_back(x);
        ys.push_back(y);
        if (hypot(x,y)<=1)
        {
                count++;
        }
    }
    cout << fmt::format("pi ~ {:.10f}",  4.0  * count / max_count) << endl;
    plot_data(xs, ys);
}