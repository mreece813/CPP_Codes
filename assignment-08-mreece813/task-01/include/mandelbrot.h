#pragma once

#include <vector>
#include <nlohmann/json.hpp>

namespace fractal
{

class mandelbrot
{
public:
    mandelbrot();

    mandelbrot(const nlohmann::json &j);

    void compute();

    void visualize() const;

    void serialize(const std::string &filename) const;

private:
    int get_escape_velocity(std::complex<double> c);

    std::vector<std::vector<int>> set {};
    double x_min = -2.0;
    double x_max = 0.5;
    double y_min = -1.25;
    double y_max = 1.25;
    double step = 0.001;

    int max_iterations = 500;
    int width = 2500;
    int height = 2500;
};

}
