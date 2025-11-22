#include <iostream> // variant number 8
#include <vector>
#include <cmath>
using std::cout;
using std::cin;

void check_the_table(std::vector<short>& table, short length) {
	cout << "[ ";
	if (table.empty()) { // length == 0 would also work
		cout << "Empty ";
	}
	else {
		for (short i = 0; i < length;++i) {
			cout << table[i] << ' ';
		}
	}
	cout << "]\n";
}

void add_at_the_beginning(std::vector<short>& table, short& length, short value) {
	table.push_back(length + 1);
	length++;
	for (short i = length - 1; i > 0;--i) {
		std::swap(table[i], table[i - 1]);
	}
	table[0] = value;
}

void add_at_the_end(std::vector<short>& table, short& length, short value) {
	table.push_back(length + 1);
	table[length] = value;
	length++;
}

void clear_the_table(std::vector<short>& table, short& length) { 
	table.clear(); // table.resize(0) would also work
	length = 0; // 
}

void find_element_by_value(std::vector<short>& table, short length, short value) {
	std::vector<short> placements_of_value;
	short temp_length = 0;
	for (short i = 0; i < length; ++i) {
		if (table[i] == value) {
			placements_of_value.push_back(temp_length + 1);
			placements_of_value[temp_length] = i;
			temp_length++;
		}
	}
	cout << "Value is on this position(s): ";
	check_the_table(placements_of_value, placements_of_value.size());

}

void do_the_thing(std::vector<short>& table, short& length) { // task, that depends on your varient
	check_the_table(table, length);
	short max_v = SHRT_MIN;
	short min_v = SHRT_MAX;
	for (short i = 0; i < length;++i) {
		if (table[i] > max_v) {
			max_v = table[i];
		}
		if (table[i] < min_v) {
			min_v = table[i];
		}
	}
	if ((max_v == 0 or min_v == 0 or ((max_v / abs(max_v)) != (min_v / abs(min_v)))) and abs(max_v - min_v) <= 2) {
		add_at_the_beginning(table, length, 0);
		add_at_the_end(table, length, 0);
	}
	else {
		add_at_the_end(table, length, 0);
	}
	check_the_table(table, length);
}

int main() {
	short length = 4;
	std::vector<short> table(length);
	short reserved = 20; // just in case, don't think we need more
	table.reserve(reserved);
	for (short i = 0; i < length;++i) { // some start values
		table[i] = i;
	}
	short value;
	short end = 0;
	while (end==0) {
		cout << "What do you want to do?\n0: Exit\n1: Check the table\n2: Add the element at the beginning\n3: Add the element at the end\n4: Clear the table\n5: Find the element\n6: Do the thing\n";
		short way;
		cin >> way;
		switch (way) {
		case 0: end = 1; break;
		case 1: check_the_table(table, length); break;
		case 2: cout << "Value of new element: "; cin >> value; add_at_the_beginning(table, length, value); break;
		case 3: cout << "Value of new element: "; cin >> value; add_at_the_end(table, length, value); break;
		case 4: clear_the_table(table, length); break;
		case 5: cout << "Value of the element that we're serching for: "; cin >> value; find_element_by_value(table, length, value); break;
		case 6: do_the_thing(table, length); break;
		default: cout << "There were no options like that\n"; break;
		}
	}
}

