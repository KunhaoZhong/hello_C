
#include <iostream>
#include "vector2d.H"
#include "rectangle.H"

int main() {

    //Excercise functoins in rectangle
    auto rect = Rectangle(3.0, 3.0);
    double area = rect.area();
    double perimeter = rect.perimeter();
    bool is_square = rect.is_square();

    std::cout << area << std::endl;
    std::cout << perimeter << std::endl;
    std::cout << is_square << std::endl;

    //Excercise functoins in vector multiply and devide
    Vector2d v1(1, 2);
    Vector2d v2(2, 4);

    double a = 2.0;

    std::cout << v1 * a << std::endl;
    std::cout << a * v1 << std::endl;
    std::cout << v2 / a << std::endl;
    std::cout << v2.abs() << std::endl;
    std::cout << v2.dot(v1) << std::endl;

}