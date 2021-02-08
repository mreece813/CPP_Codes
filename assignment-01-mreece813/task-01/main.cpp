#include <iostream>
using namespace std;

int main()
{
    int side;
    float sa;
    float volume;
    cout << "What is your side length?" << endl;
    cin >> side;
    sa = (side*side*6);
    volume = (side*side*side);
    cout << "" << sa << endl;
    cout << "" << volume << endl;
    cout << endl;
    return 0;
}