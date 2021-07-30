#include <iostream>
#include <cmath>


using namespace std;

enum class PointType {
    cartesian, 
    polar
};

// here we cannot have 2 Point constructors for cartesian and polar
// because both of the constructors will have (float, float) arguments
// we have to introduce enum for type differenciation

// then we introduce static methods for object creation -- this is called as factory methods
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

public:
    float x, y;

    static Point NewCartesian(float x, float y) {
        return {x, y};
    }

    static Point NewPolar(float r, float theta) {
        return { r*cos(theta), r*sin(theta) };
    }

    friend ostream &operator<<(ostream& os, Point &p) {
        os << "x: " << p.x << ", y: " << p.y;
        return os;
    }

};

int main() {

    auto p = Point::NewPolar(5, M_PI_4);

    cout << p << endl;

    return 0;
}