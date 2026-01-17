#include "task1.hpp"
#include <iostream>
using std::cout;
using std::cin;

void start_task1() {
	short input[3], a;
	cout << "Welcome to starting function for task1.\nGive 3 numbers (0 equals skip of one, for the work we need 1 or 3 in the end): ";
		short count_0 = 0;
		for (short i = 0; i < 3; ++i) {
			cin >> input[i];
			if (input[i]==0){
				count_0 +=1;
			}
			else { 			  // Так вполне можно запомнить единственное число != 0.
				a = input[i]; //В случае 3х чисел переменная просто не будет ни на что влиять, а случай 2х нам и так не интересен
						  
			}
		}
		if (count_0 == 0){
			cout << execution(input[0],input[1],input[2]);
		}
		else if (count_0 == 2){
			cout << execution(a);
		}
		else {
			cout << "0 or 2 numbers were given. We need 1 or 3 to work with, try again please";
		}
}

int execution(int a) {
	cout << "Using 'find closest multiply of five' function for 1 number: ";
	if (a%5 == 0){
		return a;
	}
	int lower_one = a - a%5;
	int upper_one = a + (5 - a%5);
	if ((upper_one - a)<(a - lower_one)) {
		return upper_one;
	}
	else {
		return lower_one;
	}
}

int execution(short a, short b, short c) {
	cout << "Using 'find summ of max and min' function for 3 numbers: ";
	short max_of_em = std::max(c, std::max(a,b));
	short min_of_em = std::min(c, std::min(a,b));
	int sum = max_of_em + min_of_em;
	return sum;
}