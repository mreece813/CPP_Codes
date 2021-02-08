#pragma once

#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <ruc-sci-comp/disable_for_test.hpp>

namespace ruc_sci_comp
{
void serialize(const std::string &filename,
               const std::vector<std::vector<int>> &set,
               int width,
               int height)
{
    std::ofstream ofs(filename);
    ofs << width << "\n";
    ofs << height << "\n";
    for (auto &row : set)
    {
        std::copy(std::begin(row), std::end(row), std::ostream_iterator<int>(ofs, " "));
        ofs << "\n";
    }
}

}
