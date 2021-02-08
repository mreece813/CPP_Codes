#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
using namespace std;

// -----------------------------------------------------------------------------
// Uncomment the line that is the correct answer!
//
// Select the function signature that properly modifies the input data so that
// the change to that data is reflected in main.
// -----------------------------------------------------------------------------

// void update(vector<int> d)

 void update(vector<int> &d)

// void update(vector<int> *d)

// void update(vector<int> d&)

// -----------------------------------------------------------------------------
{
    sort(begin(d), end(d));
}

int main()
{
    vector<int> data(20);
    mt19937_64 eng(1337);
    generate(begin(data), end(data), [&](){return eng();});

    update(data);

    copy(begin(data), end(data), ostream_iterator<int>(cout, ","));
    cout << endl;
}
