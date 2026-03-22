#include "Potion.hpp"
#include <random>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace {
int rand_0_1() {
    std::random_device r_value;
    std::mt19937_64 r_base(r_value());
    std::uniform_int_distribution<> r_limit(0, 1);
    return r_limit(r_base);
}
}

void ptn::Potion::remove_ingredient(string what) {
    for (size_t i = 0; i < ingredients_.size(); ++i) {
        if (ingredients_[i] == what) {
            ingredients_.erase(ingredients_.begin() + i);
        }
    }

    const auto it = std::find(ingredients_.begin(), ingredients_.end(), what);
    ingredients_.erase(it);


    //auto t = remove(ingredients_.begin(), ingredients_.end(), what);
    //ingredients_.erase(t, ingredients_.end());
}
void ptn::Potion::merge_ingredients(const Potion& other) {
    int f = 1;
    for (size_t i = 0; i < other.ingredients_.size(); i++) {
        for (int j = 0; j < ingredients_.size(); j++) {
            if (ingredients_[j] == other.ingredients_[i]) {
                ingredients_.emplace_back(other.ingredients_[i] + "(additional)");
                f = 0;
            }
        }
        if (f == 1) {
            ingredients_.emplace_back(other.ingredients_[i]);
        }
    }
}
void ptn::Potion::copy_base(const Potion& other) {
    remove_ingredient(bases[type_].description);
    type_ = other.type_;
    ingredients_.emplace_back(bases[type_].description);
}

ptn::Potion::Potion() { 
    label_ = "Untitled";
    description_ = "Empty bottle.";
    ingredients_.emplace_back(bases[0].description);
    volume_ = relative_zero;
    price_ = 1;
    type_ = 0;
    //cout << "[construct] You took an empty bottle.\n";
}

ptn::Potion::Potion(const Potion& other) { // �����������
    label_ = other.label_;
    description_ = other.description_;
    ingredients_ = other.ingredients_;
    volume_ = other.volume_;
    price_ = other.price_;
    type_ = other.type_;
    //cout << "[construct] You brewed exactly the same potion as before.\n";
}
ptn::Potion::Potion(string label, string descriprion, vector <string> ingredients, int type_of_base, float volume, int price) : //������� ����������
    label_(label), description_(descriprion), type_(type_of_base), ingredients_(ingredients), volume_(volume), price_(price) {
    ingredients_.push_back(bases[type_of_base].description);
    //cout << "[construct] You brewed new potion.\n";
}
ptn::Potion::~Potion() {
    ingredients_.clear();
    //cout << this << "[destruct] Your potion turned sour.";
}
ptn::Potion& ptn::Potion::operator+ (const Potion& other) {
    if (rand_0_1()) {
        label_ = other.label_;
    }
    if (other.volume_ > volume_) {
        copy_base(other);
    }
    merge_ingredients(other);
    volume_ += other.volume_;
    price_ += other.price_;
    return *this;
}
ptn::Potion& ptn::Potion::operator+= (const Potion& other) {
    if (rand_0_1()) {
        label_ += " with addition of " + other.label_;
    }
    if (other.volume_ > volume_) {
        copy_base(other);
    }
    merge_ingredients(other);
    volume_ += other.volume_;
    price_ += other.price_;
    return *this;
}
ptn::Potion& ptn::Potion::operator* (const Potion& other) {
    if (rand_0_1()) {
        copy_base(other);
    }
    volume_ = 0.8 * (volume_ + other.volume_);
    vector <string> temp_ingredients_;
    for (int i = 0; i < other.ingredients_.size(); i++) {
        for (int j = 0; j < ingredients_.size(); j++) {
            if (ingredients_[j] == other.ingredients_[i]) {
                temp_ingredients_.push_back(other.ingredients_[i]);
            }
        }
    }
    ingredients_ = temp_ingredients_;
    ingredients_.push_back("Tail");
    ingredients_.push_back("Water");
    return *this;
}

const string ptn::Potion::get_label() { return label_; } // manual value return 
const string ptn::Potion::get_description() { return description_; }
const float ptn::Potion::get_volume() { return volume_; }
const int ptn::Potion::get_price() { return price_; }

const void ptn::Potion::print_ingredients() { // cout included
    for (int i = 0; i < ingredients_.size(); i++) {
        cout << ingredients_[i] << ' ';
    }
    cout << '\n';
}
const void ptn::Potion::print_base() {
    if (type_ == 0) {
        cout << "[base] Nothing but an air.\n";
    }
    else {
        cout << "[base] Brewed with " + bases[type_].description + " as basic ingredient.\n";
    }
}
const void ptn::Potion::print_info() {
    cout << "----------------\n" << get_label() << "\nDesc: " << get_description() << '\n';
    print_base();
    print_ingredients();
    cout << "V: " << get_volume() << "\nC: " << get_price() << "\n----------------\n";
}

void ptn::Potion::set_price(int price) {
    if (price < 0) {
        throw std::invalid_argument("Price is less than 0.");
    }
    price_ = price;
}
void ptn::Potion::empty_the_glass() {
    if (volume_ <= relative_zero) {
        cout << "The glass is already empty.\n";
    }
    else {
        volume_ = relative_zero;
        type_ = 0;
        price_ = 1;
        ingredients_.clear();
        ingredients_.push_back(bases[0].description);
        description_ = "Empty bottle.";
        cout << "You poured the potion out, only little drops remain.\n";
    }
}
void ptn::Potion::drink() {
    if (volume_ <= relative_zero) {
        cout << "The glass is already empty.\n";
    }
    else {
        volume_ -= 0.1;
        cout << "You open a bottle and make a tiny sip.\n";
    }
}
void ptn::Potion::change_base() {
    cout << "Please, choose the basic ingredient:\n";

    int t;
    cin >> t;
    if (!(1 <= t and t <= amount_of_bases)) {
        throw std::invalid_argument("There're no such a base in our basement.");
    }
    else {
        remove_ingredient(bases[type_].description);
        type_ = t;
        ingredients_.push_back(bases[type_].description);
        volume_ += 0.3;
        cout << "You added " << bases[type_].description << " into your cattle. Now you have different potion.\n";
    }
}
