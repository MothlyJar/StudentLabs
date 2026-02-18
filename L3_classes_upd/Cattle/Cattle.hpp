#pragma once
#include "Potion.hpp"
#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

namespace ptn {
class Cattle {
private:
	int type_;
	float limit_volume_;
	float volume_;
	vector <string> ingredients_;
	const float relative_zero = 0.001;
public:
	Cattle();
    Cattle(const Cattle& other);
    Cattle(int type_of_base, float limit, float volume, vector<string> ingredients);
    Potion brew_potion();
	void full_with_potion(Potion& potion);
};
}