#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
using namespace std;

//------------------------------------------------------------------------------
// Fix the code below that is broken! Do not modify any code marked as valid! 
//
// This program should generate a random 10x10 matrix of integers that is 
// represented as a vector of vectors.
//------------------------------------------------------------------------------
int main()
{
    mt19937_64 eng(1234);
    uniform_int_distribution dis(0, 10);

    vector<vector<int>> matrix(10, vector<int>(10)); // this line is fine, do not modify it!

    for (auto &row : matrix)
    {
        for (auto &cell : row)
        {
            cell = dis(eng);
        }
    }

    //-------------------------------------------------------------------------
    // this code below is fine, do not modify it!
    for (const auto &row : matrix)
    {
        cout << "<";
        copy(begin(row), end(row), ostream_iterator<int>(cout, ","));
        cout << ">" << endl;
    }
    cout << flush;
    //-------------------------------------------------------------------------
}
