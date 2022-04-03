#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {

private:

    // our member data
    double l; //length
    double h; //height

public:

    // default constructor
    Rectangle()
        : l{0.0}, h{0.0}
    {}

    // another constructor

    Rectangle(double _l, double _h)
        : l{_l}, h{_h}
    {}

    // setters

    inline void set_length(double _l) {l = _l;}
    inline void set_height(double _h) {h = _h;}

    // operators

    // compute area
    
    double area() {
        return l * h;
    }

    // compute perimeter
    double perimeter() {
        return (l+h) * 2;
    }

    //Is the rectangle a square
    bool is_square(){
        return l==h;
    }

};

#endif