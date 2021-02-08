#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

// -----------------------------------------------------------------------------
// Uncomment the line that is the correct answer!
//
// Which line properly forward declares the function scale?
// -----------------------------------------------------------------------------

// scale(vector<double> x, dobule s);

// void scale(vector<double> x, double s);

// vector<double> scale(x, s);

 vector<double> scale(vector<double> x, double s);

// -----------------------------------------------------------------------------

int main()
{
    auto sd = scale({1.0, 3.0, 5.0, 10.0}, 3.5);
    copy(begin(sd), end(sd), ostream_iterator<double>(cout, ","));
    cout << endl;
}

vector<double> scale(vector<double> x, double s)
{
    transform(begin(x), end(x), begin(x), [s](double e){ return e * s;});
    return x;
}
