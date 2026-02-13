#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace ptn {
struct Base {
    int type;
    string name;
    string description;
    const void print() {
        cout << type << '. ' << name << ': ' << description << endl;
    }
};
struct Ingredient {
    string name;
    string description;
    string effect;
    const void print() {
        cout << name << ': ' << description << '. ' << effect << endl;
    }
};

const int amount_of_bases = 8;
inline const Base bases[amount_of_bases]{ //inline like pragma once
    {0, "Air", "Nothing but an air"},
    {1, "Water", "Translucent purified water"},
    {2, "Orange juice", "Bright orange liquid with familiar citrus scent"},
    {3, "Beer",""},
    {4, "Unicorn's blood","Thick liquid thining with silver"},
    {5, "Abyss","Black piece of something completely obsorbing the light"},
    {6, "Head of Cerberus","Chopped off head of demonic dog quard"},
    {7, "Set of unknown mushrooms","Bright colored couple of different mushrooms. Most likely pousonous"}
};

class Potion {
private:
    string label_;
    string description_;
    vector <string> ingredients_;
    int type_;
    float volume_;
    int price_;

    const float relative_zero = 0.00001;

    void remove_ingredient(string what);
    void merge_ingredients(const Potion& other);
    void copy_base(const Potion& other);
public:
    Potion();
    Potion(const Potion& other);
    Potion(string label, string descriprion, vector <string> ingredients, int type_of_base, float volume, int price);
    ~Potion();
    Potion& operator+ (const Potion& other);
    Potion& operator+= (const Potion& other);
    Potion& operator* (const Potion& other);

    const string get_label();
    const string get_description();
    const float get_volume();
    const int get_price();

    const void print_ingredients();
    const void print_base();
    const void print_info();
    void set_price(int price);
    void empty_the_glass();
    void drink();
    void change_base();  
};
}