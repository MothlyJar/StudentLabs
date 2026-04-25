#include "Cattle.hpp"
#include "Potion.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
using ptn::bases;
using ptn::Potion;
using ptn::Cattle;


ptn::Cattle::Cattle() {
    label_ = "Basic one";
    type_ = 0;
    limit_volume_ = 5;
    volume_ = relative_zero;
    ingredients_.emplace_back(bases[0].name);
}
ptn::Cattle::Cattle(const Cattle& other) {
    label_ = other.label_;
    type_ = other.type_;
    limit_volume_ = other.limit_volume_;
    volume_ = other.volume_;
    ingredients_ = other.ingredients_;
}
ptn::Cattle::Cattle(string label, int type_of_base, float limit_volume, float current_volume, vector<string> ingredients) : label_(label), type_(type_of_base), limit_volume_(limit_volume), volume_(current_volume), ingredients_(ingredients) {
    ingredients_.emplace_back(bases[type_of_base].name);
}
string ptn::Cattle::get_label_() {return label_;}
int ptn::Cattle::get_type_() {return type_;}
float ptn::Cattle::get_limit_volume_() {return limit_volume_;}
float ptn::Cattle::get_volume_() {return volume_;}
vector<string> ptn::Cattle::get_ingredients_() {return ingredients_;}
const void ptn::Cattle::print_ingredients() { 
    for (int i = 0; i < ingredients_.size(); i++) {
        cout << ingredients_[i] << ' ';
    }
    cout << '\n';
}
const void ptn::Cattle::print_info() {
    cout << "----------------\n" << label_ << "\nMax volume: " << limit_volume_ << "\nCurrent volume: " << volume_ << "\nCurrent potion's base: "<< endl;
    if (type_ == 0) {
        cout << "Nothing but an air." << endl;
    }
    else {
        cout << bases[type_].name << endl;
    }
    print_ingredients();
    cout << "----------------" << endl;
}
void ptn::Cattle::empty_the_cattle() {
    if (volume_ <= relative_zero) {
        cout << "The cattle is already empty." << endl;
    }
    else {
        volume_ = relative_zero;
        type_ = 0;
        ingredients_.clear();
        ingredients_.emplace_back(bases[0].name);
        cout << "You poured the potion out of the cattle, only little drops remain." << endl;
    }
}
ptn::Potion Cattle::brew_potion() {
    cout << "What bottle did you choose? (volume)" << endl;
    float volume;
    cin >> volume;
    if (type_ == 0) {
        Potion Temp;
        Temp.set_volume(volume);
        cout << "You have nothing to brew potion with. You just stand there with an empty glass." << endl;
        return Temp;
    }
    else {
        cout << "What's the name of the potion?" << endl;
        string label;
        cin >>  label;
        cout << "How you would describe the potion?" << endl;
        string description;
        cin >> description;
        cout << "What price you're charging your potion for?" << endl;
        int price;
        cin >> price;
        if (volume > volume_)  {
            volume = volume_;
            volume_ = relative_zero;
        }
        else {
            volume_ -= volume;
        }
        return Potion(label, description, ingredients_, type_, volume, price);
    }
}
void Cattle::full_with_potion(Potion& potion) {
    if (limit_volume_ < potion.get_volume()) {
        cout << "Cattle is too small. You've spilled some potion." << endl;
        volume_ = limit_volume_;
    }
    else {
        volume_ = potion.get_volume();
    }
    type_ += potion.get_type();
    ingredients_ = potion.get_ingredients();
}