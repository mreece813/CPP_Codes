#include <iostream>
#include <string>
#include <fmt/format.h>
using namespace std;

int main() {
    string dangerous = fmt::format("It's {0} to go alone! Take this.", "dangerous");
    cout << dangerous << endl;
    double a = 22.0/7.0;
    cout << fmt::format("22.0/7.0 = {0:.0f}", a) << endl;
    cout << fmt::format("22.0/7.0 = {0:.3f}", a) << endl;
    cout << fmt::format("22.0/7.0 = {0:.7f}", a) << endl;
    cout << fmt::format("{0:.5f},{1:.5f},{2:.5f}", 3.14, 1.414, 9.81) << endl;
}