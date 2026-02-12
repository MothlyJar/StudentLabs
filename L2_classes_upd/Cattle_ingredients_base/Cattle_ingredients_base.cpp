#include "Potion.hpp"
#include "Cattle_ingredients_base.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

template<typename Option>
void option_print(const Option opts[], int n, int start) {
    for (int i = start; i < n;i++) {
        cout << opts[i].name << ": " << opts[i].type << "; " << opts[i].description << '\n';
    }
}

Cattle::Cattle() {
    type_ = 0;
    volume_ = relative_zero;
    ingredients_.push_back(bases[0].name);
}
Cattle::Cattle(const Cattle& other) {
    type_ = other.type_;
    volume_ = other.volume_;
    ingredients_ = other.ingredients_;
}
Cattle::Cattle(int type_of_base, float volume, vector<string> ingredients) : type_(type_of_base), volume_(volume), ingredients_(ingredients) {
    ingredients_.push_back(bases[type_of_base].name);
}
Potion& Cattle::brew_potion() {

};
