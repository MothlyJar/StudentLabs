#include <iostream>
#include "task1.cpp"
#include "task2.cpp"
using std::cout;
using std::cin;

short current_task;

int main() {
	cout << "What task do you want to see? (1 or 2): ";
	cin >> current_task;
	if (current_task == 1) {
		start_task1();
	}
	else if (current_task == 2) {
		int number;
		cout << "Welcome to the start of task2.\nGive one number: ";
		cin >> number;
		start_task2(number);
	}
	else {
		cout << "There are no such a task";
	}

}
