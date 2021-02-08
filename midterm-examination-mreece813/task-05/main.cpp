#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main()
{
    vector<int> data(100);
    mt19937_64 eng(1337);
    generate(begin(data), end(data), [&](){return eng();});

    // -------------------------------------------------------------------------
    // Write a for-loop that iterates over the vector named data and prints (on
    // its own line) any element that is divisible by 7. You may use a for-loop
    // for a for-range loop.
    // -------------------------------------------------------------------------
    for(auto &i : data)
    {
        if( i % 7 == 0)
        {
            cout << i << endl;
        }
    }


    // -------------------------------------------------------------------------
}
