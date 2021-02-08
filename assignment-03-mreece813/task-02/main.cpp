#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ruc-sci-comp/data.hpp>
#include <ruc-sci-comp/plot.hpp>

using namespace std;

double divide(double x)
{
    x = x/100;
    return  x;
}
int main()
{
    vector<double> vec;
    vector<double> vec2;
    vec = generate_data();
    vec2.resize(vec.size());
    transform(vec.begin(), vec.end(), vec2.begin(), divide);
    double mean = accumulate(vec2.begin(), vec2.end(), 0.0)/vec2.size();
    double min = *min_element(vec2.begin(), vec2.end()); 
    double max = *max_element(vec2.begin(), vec2.end());
    cout << mean << endl;
    cout << min << endl; 
    cout << max  << endl; 
}