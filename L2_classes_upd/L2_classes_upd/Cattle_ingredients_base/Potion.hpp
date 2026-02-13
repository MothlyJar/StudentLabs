#pragma once
#include <string>
#include <vector>
using namespace std;

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
