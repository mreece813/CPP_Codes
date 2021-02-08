#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

//------------------------------------------------------------------------------
// Write a class called `rigid_body` as detailed below. The purpose of this
// class is to represent circular objects in 2-dimensional space. In a
// physically realistic setting, no two objects can occupy the same space.
// Such an event is called a collision. However during a simulation as we move
// objects around through space, it is possible that the model will direct the
// objects into positions that would be physically impossible, and so we want to 
// write a basic function to determine when we have "accidentally" done this.
//
// The rigid_body class should have the following members:
//
// 1) a double called radius with a default of 1.0
// 2) a double called center_x with a default value of 0.0
// 3) a double called center_y with a default value of 1.0
//
// 4) a default constructor
//
// 5) a constructor that takes in three doubles and sets each of the three
//    doubles mentioned above.
//
// 6) a function called `detect_collision` that returns a bool, and takes in
//    another rigid_body object as an argument (you can name it o, or other).
//
//    This function should use basic geometry to determine if the two rigid_body
//    objects are occupying the same space (colliding). We can do this simply by
//    checking the distance between the two center's of the rigid body, and
//    checking if that distance is less than the sum of the two radii of the
//    rigid_body objects.
//      * get the difference in x values between the center points, call this dx
//      * get the difference in y values between the center points, call this dy
//      * use std::hypot to get the distance using dx and dy
//      * return the equality check between the distance and the sum of the
//        radii
//
// Remember that rigid_body is a data type that we are defining, and that we can
// reach inside of any instance to access it members. When we pass a rigid_body
// into a function, it has its own copies of every variable and function defined
// by the class.
//------------------------------------------------------------------------------
// Answer here
class rigid_body
{
public:
    double radius = 1.0;
    double center_x = 0.0;
    double center_y = 1.0;
    rigid_body() = default;
    rigid_body(double r, double x, double y)
    {
        radius = r;
        center_x = x;
        center_y = y;
    }
    bool detect_collision(rigid_body o)
    {
        double dx = center_x - o.center_x;
        double dy = center_y - o.center_y;
        double distance = o.radius + radius;
        double h = hypot(dx,dy);
        return h <= distance;
    };
};



// End of answer
//------------------------------------------------------------------------------
// Do not modify this code below!
int main()
{
    rigid_body rb1;
    rigid_body rb2(3.0, 2.0 * sqrt(2.0), 2.0 * sqrt(2.0));
    rigid_body rb3(2.0, 2.0, 2.0);
    rigid_body rb4(10.0, 50.0, 5.0);
    cout << boolalpha;
    cout << rb1.detect_collision(rb2) << endl;
    cout << rb1.detect_collision(rb3) << endl;
    cout << rb1.detect_collision(rb4) << endl;
}
