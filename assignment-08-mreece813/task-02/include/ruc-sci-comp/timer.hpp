#pragma once

#include <chrono>
#include <iostream>
#include <fmt/format.h>
#include <ruc-sci-comp/disable_for_test.hpp>

namespace ruc_sci_comp
{
struct timer
{
    timer() = default;

    timer(std::ostream &o):
        start(std::chrono::high_resolution_clock::now()),
        os(o)
    {}

    ~timer()
    {
        if (ruc_sci_comp::disable_for_test())
        {
            return;
        }

        auto t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count();
        os << fmt::format("Time Elapsed: {} seconds", t / 1000.0) << std::endl;
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    std::ostream &os = std::cout;
};

}
