#include "pch.h"
#include "framework.h"
#include "Potion.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Base {
    string name;
    string description;
    int type;
};
struct Ingredient {
    string name;
    string description;
    string effect;
};
const Base bases[8]{
    {"Air", "Nothing but an air",0},
    {"Water", "Translucent purified water", 1},
    {"Orange juice", "Bright orange liquid with familiar citrus scent", 2},
    {"Beer","",3},
    {"Unicorn's blood","Thick liquid thining with silver",4},
    {"Abyss","Black piece of something completely obsorbing the light",5},
    {"Head of Cerberus","Chopped off head of demonic dog quard",6},
    {"Set of unknown mushrooms","Bright colored couple of different mushrooms. Most likely pousonous",7}
};

template<typename Option>
void option_print(const Option opts[], int n, int start) {
    for (int i = start; i < n;i++) {
        cout << opts[i].name << ": " << opts[i].type << "; " << opts[i].description << '\n';
    }
}

const int amount_of_bases = sizeof(bases) / sizeof(bases[0]);

class Cattle {
private:
	int type_;
	float volume_;
	vector <string> ingredients_;
	const float relative_zero = 0.001;
public:
	Cattle() {
		type_ = 0;
		volume_ = relative_zero;
        ingredients_.push_back(bases[0].name);
	}
    Cattle(const Cattle& other) {
        type_ = other.type_;
        volume_ = other.volume_;
        ingredients_ = other.ingredients_;
    }
    Cattle(int type_of_base, float volume, vector<string> ingredients) : type_(type_of_base), volume_(volume), ingredients_(ingredients) {
        ingredients_.push_back(bases[type_of_base].name);
    }
    Potion& brew_potion() {
       
    }
};