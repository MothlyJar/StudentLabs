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
	string label_;
	int type_;
	float limit_volume_;
	float volume_;
	vector <string> ingredients_;
	const float relative_zero = 0.001;
public:
	Cattle();
    Cattle(const Cattle& other);
    Cattle(string label, int type_of_base, float limit, float volume, vector<string> ingredients);
	string get_label_();
	int get_type_();
	float get_limit_volume_();
	float get_volume_();
	vector<string> get_ingredients_();
	const void print_ingredients();
	const void print_info();
	void empty_the_cattle();
    Potion brew_potion();
	void full_with_potion(Potion& potion);
};
}