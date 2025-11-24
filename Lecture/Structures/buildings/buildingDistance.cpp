#include <iostream>
#include "rectangle.hpp"
using namespace std;

int main(){

    Rectangle building1 = {{0, 10}, {10, 0}};
    Rectangle building2 = {{20, 20}, {30, 10}};

    Point b1c1 = building1.topLeft.midpoint(building1.bottomRight);
    Point b2c1 = building2.topLeft.midpoint(building2.bottomRight);

    cout << "Building 1 Center: (" << b1c1.x << ", " << b1c1.y << ") " << endl;
    cout << "Building 2 Center: (" << b2c1.x << ", " << b2c1.y << ") " << endl;

    cout << "Distance between centers: " << b1c1.distance(b2c1) << endl;
}