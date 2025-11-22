#include <iostream>
#include <array>
#include <random>
using std::cin;
using std::cout;

void see(std::array<short, 10> arr) {
	for (short i = 0; i < 10; ++i) {
		cout << arr[i] << ' ';
	}
}

void sort_value(std::array<short,10> arr) {
	for (short i = 0; i < 9; ++i) {
		for (short j = i + 1; j < 10; ++j)
			if (arr[i] < arr[j]) {
				std::swap(arr[i], arr[j]);
			}
	}
	see(arr); cout << " - In function" << '\n';
}
void sort_reference(std::array<short, 10>& arr) {
	for (short i = 0; i < 9; ++i) {
		for (short j = i + 1; j < 10; ++j)
			if (arr[i] > arr[j]) {
				std::swap(arr[i], arr[j]);
			}
	}
	see(arr); cout << " - In function" << '\n';
}

void sort_pointer(std::array<short, 10>* arr) { /////////////////////////////////////////////////////////
	for (char i = 0; i < 9; ++i) {
		for (char j = i + 1; j < 10; ++j)
			if (*(arr + i) > *(arr + j)) {
				std::swap(arr[i], arr[j]);
			}
	}
	see(*arr); cout << " - In function" << '\n';
}

int main() {
	std::random_device value;
	std::mt19937_64 base(value());
	std::uniform_int_distribution<> limit(-10, 10);

	const short length = 10;
	std::array<short, length> arr;
	for (short i = 0; i < length; ++i) {
		arr[i] = limit(base);
	}

	see(arr);
	cout << '\n';
	sort_value(arr);
	see(arr);
	cout << "Only values were given to the function: original array stays the same, function works with it's copy.\n\n";

	see(arr);
	cout << '\n';
	sort_reference(arr);
	see(arr);
	cout << "Link was given to the function: original array changes, no copying involved.\n\n";

	see(arr);
	cout << '\n';
	sort_pointer(&arr);
	see(arr);
	cout << "Pointer was given to the function:\n\n";

}