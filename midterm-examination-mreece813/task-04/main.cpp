#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<double> data {1, 2, 4, 8};
    data.reserve(5);
    data.push_back(16);
    data.push_back(32);

    size_t size = 0;
    size_t capacity = 0;

    // -------------------------------------------------------------------------
    // Uncomment the line that is the correct answer!
    //
    // Given the vector and code, what is the vector's final size and capacity?
    // NOTE: you need to uncomment both lines when selecting your answer!
    // -------------------------------------------------------------------------

    // size = 6;
    // capacity = 12;

    // size = 5;
    // capacity = 5;

    // size = 6;
    // capacity = 6;

     size = 6;
     capacity = 10;

    // -------------------------------------------------------------------------

    cout << boolalpha <<  (size == data.size() && capacity == data.capacity()) << endl;
}
