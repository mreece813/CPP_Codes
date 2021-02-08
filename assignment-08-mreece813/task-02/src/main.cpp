#include <complex>
#include <fstream>
#include <functional>
#include <thread>
#include <vector>
#include <nlohmann/json.hpp>
#include <ruc-sci-comp/timer.hpp>
#include "mandelbrot.h"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Not enough arguments provided! You must provide a configuration file!" << std::endl;
        return 1;
    }

    nlohmann::json j;
    std::ifstream ifs(argv[1]);
    ifs >> j;

    fractal::mandelbrot m(j["parameters"]);

    {
        ruc_sci_comp::timer t;
        m.threaded_compute();
    }

    m.visualize();
    m.serialize(j["output"].get<std::string>());
}
