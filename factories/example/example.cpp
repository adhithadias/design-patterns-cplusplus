#include <iostream>
#include <cmath>


using namespace std;

enum class PointType {
    cartesian, 
    polar
};

/*

1) here we cannot have 2 Point constructors for cartesian and polar
because both of the constructors will have (float, float) arguments
we have to introduce enum for type differenciation

2) then we introduce static methods for object creation -- this is called as factory methods

3) Next we add a seperate class called Factory for Point creation
In the Gand of 4, there is no Factory class, there is only factory methods and abstracts
But we are creating a concrete Factory class (not abstract)

4) We can move the PointFactory inside the Point class to keep the 
open-close principle intact because we made everything public in Point class
Now since PointFactory is inside the Point class, the private members of the Point class
are accessible from inside the PointFactory class

5) We can even make the PointFactory class private
*/
class Point {

    Point (float x, float y) : x(x), y(y) {}

    // Point (float a, float b, PointType type = PointType::cartesian) {
    //     if (type == PointType::cartesian) {
    //         x = a;
    //         y = b;
    //     }
    //     else {
    //         x = a * cos(b);
    //         y = a * sin(b);
    //     }
    // }

    float x, y;

public:
    friend ostream &operator<<(ostream& os, Point &p) {
        os << "x: " << p.x << ", y: " << p.y;
        return os;
    }

    struct PointFactory {
        PointFactory() {}
        static Point NewCartesian(float x, float y) {
            return {x, y};
        }

        static Point NewPolar(float r, float theta) {
            return { r*cos(theta), r*sin(theta) };
        }
    };

};

int main() {

    auto p = Point::PointFactory::NewPolar(5, M_PI_4);

    cout << p << endl;

    return 0;
}