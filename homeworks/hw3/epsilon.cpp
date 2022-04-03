 #include <iostream>
 #include <limits>

  int main() {
 
    // std::cout << "epsilon of float = " << std::numeric_limits<double>::epsilon() << std::endl;
    double epsilon = std::numeric_limits<double>::epsilon();
    // std::cout << epsilon << std::endl;
    bool equal_one_epsilon = false;
    bool equal_two_epsilon = false;
    bool equal_half_epsilon = false;

    if (1.0 == 1.0 + epsilon){
        equal_one_epsilon = true;
    }

    if (1.0 == 1.0 + epsilon * 2.0){
        equal_two_epsilon = true;
    }

    if (1.0 == 1.0 + epsilon * 0.5){
        equal_half_epsilon = true;
    }

    std::cout << "one epsilon comparison: " << equal_one_epsilon << std::endl;
    std::cout << "two epsilon comparison: " << equal_two_epsilon << std::endl;
    std::cout << "half epsilon comparison: " << equal_half_epsilon << std::endl;


}