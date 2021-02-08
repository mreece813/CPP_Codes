#pragma once

#include <cstdlib>
#include <vector>
#include <malen/bokeh.h>
#include <ruc-sci-comp/disable_for_test.hpp>

namespace ruc_sci_comp
{
void visualize(const std::vector<std::vector<int>> &set,
               int width,
               int height,
               int max_iterations)
{
    if (disable_for_test())
    {
        return;
    }

    setenv("PYTHONPATH", ".:..:../..", 1);
    malen::Bokeh mb;

    auto x_range =  malen::kwarg("x_range", std::vector<int>{0, width});
    auto y_range =  malen::kwarg("y_range", std::vector<int>{0, height});
    auto figure = mb.make_new_figure("Mandelbrot Set", x_range, y_range);

    auto palette = malen::kwarg("palette", "Spectral11");
    auto low = malen::kwarg("low", 0);
    auto high = malen::kwarg("high", max_iterations);
    auto color_mapper = mb.color_mapper(
        "LinearColorMapper",
        palette,
        low,
        high
    );
    mb.image(figure, set, malen::kwarg("color_mapper", color_mapper));
    mb.generate_html(figure, "mandelbrot.html");
}

}
