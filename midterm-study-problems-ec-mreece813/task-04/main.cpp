#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> data {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //-------------------------------------------------------------------------
    // Answer within the comment-block here
    for (auto &i : data)
    {
        i *= i;
    }


    // End of answer
    //-------------------------------------------------------------------------
    std::copy(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, "\n"));
    std::cout << std::flush;
}
