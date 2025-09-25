// Вариант 8. Для целого числа Х вычислить противоположное, а также значение корня 2-й и 5-й степени. (Разные решения)
#include <iostream> // подгрузка библиотек ввода/вывода и математических функций
#include <cmath>
using namespace std; // для чистоты письма команд без std везде

int main()
{
    int intspace = sizeof(int)*8; // проверка веса на конкретном ПО + перевод в биты
    int floatspace = sizeof(float)*8;
    int number; // не unsigned, т.к. целые числа бывают и отрицательные
    cout << "Number, please: ";
    cin >> number;
    
    int reverse = -number;
    float result2 = sqrt(number); // float для поддержки бесконечных дробных результатов. При отрицательном числе корень не посчитает, оно и правильно
    float result5 = number/abs(number)*pow(abs(number),0.2f); // извлечение нечётного корня с учётом исходного знака
    
    cout << number << "\nReverse(int): "<< reverse << "; Root2(float): "<< result2 << "; Root5(float): "<< result5 << ";\n";
    
    cout << "For number and reverse: int. Memory reqired: " << intspace << " bits, min value = " << -pow(2,(intspace-1)) << ", max value = " << pow(2,(intspace-1))-1 << "\n";
    cout << "For result2 and result5: float. Memory reqired: " << floatspace << " bits, min value = " << "1,175494351E–38" << ", max value = " << "3,402823466E+38";
    
    return 0;
}