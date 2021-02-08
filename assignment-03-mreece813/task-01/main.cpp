#include <iostream>
#include <vector>
#include <ruc-sci-comp/data.hpp>
#include <ruc-sci-comp/plot.hpp>
using namespace std;

int main()
{
    vector<double> vec;
    vec = generate_data();
    for(double i = 0; i < vec.size(); i++) 
    {
        vec.at(i) = vec.at(i)/100.0;
    }
    double mean = 0;
    for(double y = 0; y < vec.size(); y++) 
    {
        mean = mean + vec.at(y);
    }
    mean = mean/vec.size();
    double min = 2.0;
    double max = -1;
    for(double x = 0; x < vec.size(); x++) 
    {
        if(min > vec.at(x))
        {
            min = vec.at(x);
        }
        if(max < vec.at(x))
        {
            max = vec.at(x);
        }
    }
    plot_data(vec,mean, min,max);
    cout << mean << endl;
    cout << min << endl;
    cout << max << endl;
}