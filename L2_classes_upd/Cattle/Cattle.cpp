#include "Cattle.hpp"
#include "Potion.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
using ptn::bases;

ctl::Cattle::Cattle() {
    type_ = 0;
    volume_ = relative_zero;
    ingredients_.push_back(bases[0].name);
}
ctl::Cattle::Cattle(const Cattle& other) {
    type_ = other.type_;
    volume_ = other.volume_;
    ingredients_ = other.ingredients_;
}
ctl::Cattle::Cattle(int type_of_base, float volume, vector<string> ingredients) : type_(type_of_base), volume_(volume), ingredients_(ingredients) {
    ingredients_.push_back(bases[type_of_base].name);
}
ptn::Potion ctl::Cattle::brew_potion() {
    return {};
}