#include <iostream>
#include <limits>
using std::cin;
using std::cout;

int main() {
    //Task 1 - упорядочить по возрастанию, если сумма первых трёх больше 100
    const short massive_space = 11;
    int massive[massive_space];
    cout << "Task number 1. Add values to your massive:\n";
    for (short i = 0; i < massive_space; ++i) { // вводим числа
        cin >> massive[i];
    }
    if (massive[0] + massive[1] + massive[2] > 100) { // если
        for (int i = 0; i < massive_space - 1;++i) { // сортируем
            for (int j = i + 1; j < massive_space;++j) {
                if (massive[j] < massive[i]) {
                    std::swap(massive[i], massive[j]);
                }
            }
        }
        cout << "Your sorted massive is: ";
        for (short i = 0; i < massive_space; ++i) {
            cout << massive[i] << ' ';
        }
    }
    else {
        cout << "Summ of the first three nubmers is less than 100, we're not sorting that\n";
    }
    //Task 2 - найти столбец с максимальной суммой отриц. значений и занулить его
    const short line = 3, column = 4;
    int matrix[line][column];
    cout << "\nTask number 2. Add values to your matrix (3x4):\n"; 
    for (short i = 0; i < line; ++i) { // вносим значений
        for (short j = 0; j < column; ++j) {
            cin >> matrix[i][j];
        }
    }
    short column_with_maxns = -1; int max_ns = std::numeric_limits<int>::min();
    for (short j = 0; j < column; ++j) { // рассмотрим столбец
        int ns = 0;
        for (short i = 0; i < line; ++i) { // просуммируем отрицательные в этом столбце
            if (matrix[i][j] < 0) {
                ns += matrix[i][j];
                if (ns > max_ns) { // сравним сумму для этого столбца и максимальнужю на данный момент, запомним индекс
                    max_ns = ns;
                    column_with_maxns = j;
                }
            }
        } 
    }
    for (short i = 0; i < line; ++i) { // занулим всё в столбце с полученным индексом
        matrix[i][column_with_maxns] = 0;
    }
    cout << "First column with max summ of negative numbers: " << column_with_maxns << '(' << max_ns << ").\nNow your matrix'll look like this:\n";
    for (short i = 0; i < line; ++i) {
        for (short j = 0; j < column; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    ////Bonus task 1
    //int summ_massive[massive_space][2] = {};
    //for (short i = 0; i < massive_space; ++i) {
    //    short temp = massive[i];
    //    short summ = 0;
    //    while (temp > 0) {
    //        summ += temp % 10;
    //        temp /= 10;
    //    }
    //    summ_massive[i][1] = massive[i];
    //    summ_massive[i][2] = summ;
    //}
    //for (int i = 0; i < massive_space - 1;++i) {
    //    for (int j = i + 1; j < massive_space;++j) {
    //        if (summ_massive[i][2] < summ_massive[j][2]) {
    //            std::swap(summ_massive[i][2], summ_massive[j][2]);
    //            std::swap(summ_massive[i][1], summ_massive[j][1]);
    //        }
    //    }
    //}
    //cout << "Your sorted massive is (by summ of a digits): ";
    //for (short i = 0; i < massive_space; ++i) {
    //    cout << summ_massive[i][1] << ' ';
    //}
}