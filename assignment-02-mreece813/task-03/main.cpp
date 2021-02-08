#include <iostream>
#include <vector>
#include <ruc-sci-comp/plot.hpp>
using namespace std;

int main() 
{
    cout << "What is your launch speed?" << "\n";
    double speed = 0.0;
    cin >> speed;

    cout << "What is your launch angle?" << "\n";
    double angle_deg = 0.0;
    cin >> angle_deg;

    double angle = angle_deg * M_PI /180.0;

    double x_velocity = speed * cos(angle);
    double y_velocity = speed * sin(angle);

    vector<double> x_data;
    vector<double> y_data;

    double time = 0.0;

    while (time <10.0)
    {
        double x = x_velocity * time;
        double y = y_velocity * time - 0.5 * 9.81 * time * time;
        cout << x << " " << y << "\n";
        time += 0.25;

        x_data.push_back(x);
        y_data.push_back(y);
    }
plot_trajectory (x_data, y_data);

}