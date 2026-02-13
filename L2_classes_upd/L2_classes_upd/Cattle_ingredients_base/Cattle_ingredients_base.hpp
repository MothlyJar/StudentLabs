#include "Potion.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Base {
    string name;
    string description;
    int type;
    void print() {
        std::cout << name << std::endl;
    }
};
struct Ingredient {
    string name;
    string description;
    string effect;
};

const int amount_of_bases = 8;
/*inline*/ const Base bases[amount_of_bases]{
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
    Potion brew_potion();
};