#pragma once
#include "Potion.hpp"
#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

namespace ctl {
class Cattle {
private:
	int type_;
	float volume_;
	vector <string> ingredients_;
	const float relative_zero = 0.001;
public:
	Cattle();
    Cattle(const Cattle& other);
    Cattle(int type_of_base, float volume, vector<string> ingredients);
    ptn::Potion brew_potion();
};
}