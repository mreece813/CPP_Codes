#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> data;

    auto &a = data;
    auto &b = data;
    auto c = data;

    data.push_back(1);
    a.push_back(2);
    b.push_back(3);
    c.push_back(4);

    vector<int> answer = 
    // -------------------------------------------------------------------------
    // Uncomment the line that is the correct answer!
    //
    // What is the final value of data?
    // -------------------------------------------------------------------------

    // {1, 2, 3, 4};

     {1, 2, 3};

    // {2, 3};

    // {1, 3, 4};

    // -------------------------------------------------------------------------
    cout << boolalpha << (data == answer) << endl;
}
