/*
Для пункта 1 число А (short) вводиться с клавиатуры, номер бита i тоже. Проверить правильность ввода i и определить по заданию. 
Все числа выводить в виде “5 = 00000101”. (будем рассматривать только первые 8 бит). 
Для первого сравнения в пункте 1, вытащить значение i бита в отдельную переменную (через битовые операции).
Для пункта 2 сгруппировать кейсы если это возможно


Вариант 8

Если i бит А не равен 0 – побитово умножить А на число 5,  вывести результат.
Иначе – инвертировать все биты А, вывести на экран цепочку и значение.

Ввести с клавиатуры N – чит-код для игры bounce, с помощью switch вывести что делает этот чит-код.
В других случаях сообщить что “код не найден”. Описать только чит-коды состоящие из цифр.

*/
#include <iostream>
#include <bitset>
using namespace std;

int main() {
	//!!! - Подготовка данных
	cout << "Welcome to the preparation block for the Task number 1.\nInsert the number A: "; // запрашиваем число А
	short numberA, index;
	cin >> numberA;
	do { // запрашиваем индекс, пока он не будет корректным
		cout << "Insert the index i. It must be not negative and less than 16: ";
		cin >> index;
	} while (!((0 <= index) && (index < 16))); // Поскольку short содержит 16 битов, индекс должен быть неотрицательным, но не более 15
	cout << "The index is correct. We could start.";

	bitset<8>binary_numberA = numberA; // находим битовый вид исходного А для вывода в итогах
	short byte_i = numberA & (1 << index); // смотрим значение i бита битовой формы А
	//!!! - Пункт 1
	cout << "\nTask number 1:\n";
	if (byte_i != 0) {
		numberA &= 5;
		bitset<8>changed_binary_numberA = numberA; // находим битовый вид обновлённого А для вывода
		cout << "Process: " << binary_numberA << " & 5 (00000101) = " << changed_binary_numberA << "\nResult: " << numberA << " = " << changed_binary_numberA;
	}
	else {
		numberA = ~numberA;
		bitset<8>changed_binary_numberA = numberA; // находим битовый вид обновлённого А для вывода
		cout << "Original number A: " << binary_numberA << "\nReversed number A: " << changed_binary_numberA << " that equals " << numberA;
	}

	//!!! - Пункт 2
	cout << "\nTask number 2:\nWelcome to classic Bounce command center. Please insert one of the available codes: 787899 or 787898 to get info: ";
	int code;
	cin >> code;
	switch (code) {
	case 787899: 
		cout << "This code provides you ability to move across game levels and change gravity.\nUse additional simbols (1,3,5,#) to specify your code: ";
		char code_addition;
		cin >> code_addition;
		switch (code_addition) {
		case '1' : cout << "This code sends you to the previous level."; break;
		case '3' : cout << "This code sends you to the next level."; break;
		case '5' : cout << "This code finishes your current level."; break;
		case '#' : cout << "This code reverses gravity."; break;
		}
		break;
	case 787898: cout << "This code turns your ball into an undying beast.\nJust joking, but it's kinda true: your ball'll become invincible."; break;
	default: cout << "The code couldn't be found. Maybe there is a typo and you should try something else.";
	}
	cout << "\nThank you for choosing our services, bye!\n";
}