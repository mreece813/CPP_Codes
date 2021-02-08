#include <iostream>
#include <random>
using namespace std;

int main()
{
    mt19937_64 eng(9001);
    uniform_int_distribution<int> dis(-10,10);
    for (int i=0; i<5; i++)
    {
        cout << dis(eng) << endl;
    }
}