#include <cmath>
#include <iostream>
using namespace std;

int main() {
	// !!! - Пункт №1
	short how_many, last_num, max_value_index = -1; short max_value = -32767;
	int summ = 0;
	cout << "Welcome to Task number 1.";
	// ! - получаем количество элементов в последовательности
	do { 
		cout << "\nInsert the number that'll define lenght of the sequence: ";
		cin >> how_many;
	} while (how_many < 0);
	// ! - получаем числа последовательности
	cout << "Insert elements of the sequence:\n";
	for (short i = 1; i <= how_many; ++i) { 
		cin >> last_num;
		if ((last_num % 10 == 2) or (last_num % 10 == -2)) { // проверка окончания на 2 для положительных и отрицательных значений, суммирование
			summ += last_num;
			if (last_num > max_value) { //  max и его index
				max_value = last_num;
				max_value_index = i;
			}
		}
	}
	if (max_value_index == -1) { // вывод если ничего нет
		cout << "There were no correct numbers.";
	}
	else { // итоговый вывод
		cout << "Your summ = " << summ << "\nMax value = " << max_value << "\nIndex of number with max value: " << max_value_index;
	}

	// !!! - Пункт №2
	short X, X_new = 0, is_X_negative = 0;
	cout << "\nWelcome to Task number 2.\n";
	// ! - проверка правильности X
	do { 
		cout << "Insert number X, -1000 < X < 1000\n";
		cin >> X;
	} while ((X <= -1000) or (X >= 1000));
	// ! - запоминание минуса
	if (X < 0) { 
		is_X_negative = 1;
		X = abs(X);
	}
	// ! - смена числа
	while (X > 0) { 
		X_new *= 10;
		X_new += X % 10;
		X /= 10;
	}
	// ! - учёт минуса и вывод
	cout << "Your number is: ";
	if (is_X_negative == 0) { 
		cout << X_new;
	}
	else {
		cout << -X_new;
	}
}