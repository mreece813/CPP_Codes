#include <iostream>
#include <vector>

int main()
{
    std::vector<double> data {1.34, 3.42, 2.12, 0.101, -91.789};
    for (auto e : data)
    {
        std::cout << e << std::endl;
    }
}
