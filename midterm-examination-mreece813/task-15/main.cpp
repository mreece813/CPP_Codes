#include <cmath>
#include <iostream>
using namespace std;

//------------------------------------------------------------------------------
// Write a function named `collatz` that returns void and takes in an int as an
// argument; you can call the single argument n.
//
// This function should implement the following algorithm:
//   * while n is not equal to 1:
//     * if n is even, divide n by 2
//     * else multiply n by 3 and add 1
//     * print n
//
// If implemented correctly, the function represents something called the Collatz
// Conjecture. This conjecture (not proven universally true!) posits that given
// any positive integer n: if you repeatedly halve n if it is even, or
// multiply it by 3 and add 1, you will eventually, and always, end on the value
// 1.
//
// For example, given n = 17, we end up with the following sequence:
//
// 17 ->  odd -> 17 * 3 + 1 = 52
// 52 -> even -> 52 / 2     = 26
// 26 -> even -> 26 / 2     = 13
// 13 ->  odd -> 13 * 3 + 1 = 40
// 40 -> even -> 40 / 2     = 20
// 20 -> even -> 20 / 2     = 10
// 10 -> even -> 10 / 2     = 5
//  5 ->  odd ->  5 * 3 + 1 = 16
// 16 -> even -> 16 / 2     = 8
//  8 -> even ->  8 / 2     = 4
//  4 -> even ->  4 / 2     = 2
//  2 -> even ->  2 / 2     = 1 -> DONE
//
//------------------------------------------------------------------------------
// Answer here
void collatz( int n)
{
    while(n != 1)
    {
        if (n % 2 == 0)
        {
            n = n/2;
        }
        else
        {
            n = n*3 + 1;
        }
        cout << n << endl;
    }
}


// End of answer
//------------------------------------------------------------------------------
// Do not modify this code below!
int main()
{
    collatz(1337);
}
