#include "task2.hpp"
#include <cmath>
#include <iostream>
#include <limits>
using std::cout;
using std::cin;

void start_task2(int number) {
    int intspace = sizeof(int) * 8;
    int floatspace = sizeof(float) * 8;

    int reverse = -number;
    float result2 = sqrt(number);
    float result5 = number / abs(number) * pow(abs(number), 0.2f);

    cout << "\nReverse(int): " << reverse << "; Root2(float): " << result2 << "; Root5(float): " << result5 << ";\n";

    cout << "For number and reverse: int. Memory reqired: " << intspace << " bits, min value = " << -pow(2, (intspace - 1)) << ", max value = " << pow(2, (intspace - 1)) - 1 << "\n";
    cout << "For result2 and result5: float. Memory reqired: " << floatspace << " bits, min value = " << -FLT_MAX << ", max value = " << FLT_MAX;
    
}