#include <iostream>
//#include "point.hpp"
#include "triangle.hpp"

using namespace std;

int main(){

    Point p1 = {2, 4};
    Point p2 = {4, 6};

    Point mid = p1.midpoint(p2);

    cout << "Midpoint: (" << mid.x << ", " << mid.y << ")" << endl;

}

