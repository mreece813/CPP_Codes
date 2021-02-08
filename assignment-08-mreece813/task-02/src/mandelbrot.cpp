#include <complex>
#include <iostream>
#include <thread>
#include <fmt/format.h>
#include <ruc-sci-comp/serialize.hpp>
#include <ruc-sci-comp/visualize.hpp>
#include "mandelbrot.h"

namespace fractal
{

mandelbrot::mandelbrot():
    set(height, std::vector<int>(width))
{}

mandelbrot::mandelbrot(const nlohmann::json &j):
    x_min(j["x_min"].get<double>()),
    x_max(j["x_max"].get<double>()),
    y_min(j["y_min"].get<double>()),
    y_max(j["y_max"].get<double>()),
    step(j["step"].get<double>())
{
    width = (x_max - x_min) / step;
    height = (y_max - y_min) / step;
    set.resize(height, std::vector<int>(width));

    if (j.contains("max_iterations"))
    {
        max_iterations = j["max_iterations"].get<int>();
    }

    if (j.contains("thread_count"))
    {
        thread_count = j["thread_count"].get<int>();
    }
}

void mandelbrot::compute()
{
    double x = x_min;
    double y = y_min;
    for(auto &row: set)
    {
        for(auto &element: row)
        {
            element = get_escape_velocity({x,y});
            x += step;
        }
        y += step;
        x = x_min;
    }
}

void mandelbrot::threaded_compute()
{
    auto threaded_compute_f = [&](int offset, double y_start, double y_step)
    {
        double x = x_min;
        double y = y_start;
        for (int ridx = offset; ridx < height; ridx += thread_count)
        {
            for(auto &element: set[ridx])
            {
                element = get_escape_velocity({x,y});
                x += step;
            }
            y += y_step;
            x = x_min;
        }
    };
    std::vector<std::thread> threads;
    threads.reserve(thread_count);
    for (int i = 0; i <thread_count; i++)
    {
        threads.emplace_back(
            std::thread(
                threaded_compute_f,
                 i,
                 y_min + step * i,
                 step * thread_count
            )
        );
    }
    for (auto &th : threads)
    {
        th.join();
    }

}

int mandelbrot::get_escape_velocity( std::complex<double> c)
{
    std::complex<double> z {0.0, 0.0};
    int counter = 0;
    while (std::abs(z) < 2.0 && counter < max_iterations)
    {
        z = z * z + c;
        counter++;
    }
    return counter;
}

void mandelbrot::visualize() const
{
    if (ruc_sci_comp::disable_for_test())
    {
        return;
    }
    ruc_sci_comp::visualize(set, width, height, max_iterations);
}

void mandelbrot::serialize(const std::string &filename) const
{
    ruc_sci_comp::serialize(filename, set, width, height);
}

}
