#include "Potion.hpp"
#include <random>

struct Option {
    string description;
    int type;
};
void option_print(Option opts[], int n, int start) {
    for (int i = start; i < n;i++) {
        cout << opts[i].type << ": " << opts[i].description << '\n';
    }
}
Option bases[8]{
    {"Air", 0},
    {"Water", 1},
    {"Orange juice", 2},
    {"Beer",3},
    {"Unicorn's blood",4},
    {"Abyss",5},
    {"Head of Cerberus",6},
    {"Set of unknown mushrooms",7}
};
const int amount_of_bases = sizeof(bases) / sizeof(bases[0]);

class Potion {
private:
    string label_;
    string description_;
    vector <string> ingredients_;
    int type_;
    float volume_;
    int price_;
    
    const float relative_zero = 0.001;


    void remove_ingredient(string what) {
        auto t = remove(ingredients_.begin(), ingredients_.end(), what);
        ingredients_.erase(t, ingredients_.end());
    } 
    void merge_ingredients (const Potion& other) {
        int f = 1;
        for (int i = 0; i < other.ingredients_.size(); i++) {
            for (int j = 0; j < ingredients_.size(); j++) {
                if (ingredients_[j] == other.ingredients_[i]) {
                    ingredients_.push_back(other.ingredients_[i]+"(additional)");
                    f = 0;
                }
            }
            if (f == 1) {
                ingredients_.push_back(other.ingredients_[i]);
            }
        }
    }
    void copy_base (const Potion& other) {
        remove_ingredient(bases[type_].description);
        type_ = other.type_;
        ingredients_.push_back(bases[type_].description);
    }
public:
    Potion() { //базовый
        label_ = "Untitled";
        description_ = "Empty bottle.";
        ingredients_.push_back(bases[0].description);
        volume_ = relative_zero;
        price_ = 1;
        type_ = 0;
        //cout << "[construct] You took an empty bottle.\n";
    }
    Potion(const Potion& other) { // копирование
        label_ = other.label_;
        description_ = other.description_;
        ingredients_ = other.ingredients_;
        volume_ = other.volume_;
        price_ = other.price_;
        type_ = other.type_;
        //cout << "[construct] You brewed exactly the same potion as before.\n";
    }
    Potion(string label, string descriprion, vector <string> ingredients, int type_of_base, float volume, int price) : //полного заполнения
        label_(label), description_(descriprion), type_(type_of_base), ingredients_(ingredients), volume_(volume), price_(price) {
        ingredients_.push_back(bases[type_of_base].description);
        //cout << "[construct] You brewed new potion.\n";
    }
    ~Potion() {
        //cout << this << "[destruct] Your potion turned sour.";
    }
    Potion& operator+ (const Potion& other) {
        if (rand() % 2 == 0) {
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
    Potion& operator+= (const Potion& other) {
        if (rand() % 2 == 0) {
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
    Potion& operator* (const Potion& other) {
        if (rand() % 2 == 0) {
            copy_base(other);
        }
        volume_ = 0.8*(volume_ + other.volume_);
        merge_ingredients(other);
        ingredients_.push_back("Tail");
        ingredients_.push_back("Water");
        return *this;
    }

    const string get_label() { return label_; } // manual value return 
    const string get_description() { return description_; }
    const float get_volume() { return volume_; }
    const int get_price() { return price_; }

    const void print_ingredients() { // cout included
        for (int i = 0; i < ingredients_.size(); i++) {
            cout << ingredients_[i] << ' ';
        }
        cout << '\n';
    }
    const void print_base() { 
        if (type_ == 0) {
            cout << "[base] Nothing but an air.\n";
        }
        else {
            cout << "[base] Brewed with " + bases[type_].description + " as basic ingredient.\n";
        }
    }
    const void print_info() {
        cout << "----------------\n" << get_label() << "\nDesc: " << get_description() << '\n';
        print_base();
        print_ingredients();
        cout << "V: " << get_volume() << "\nC: " << get_price() << "\n----------------\n";
    }

    void set_price(int price) {
        if (price < 0) {
            throw invalid_argument("Price is less than 0.");
        }
        price_ = price;
    } 
    void empty_the_glass() {
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
    void drink() {
        if (volume_ <= relative_zero) {
            cout << "The glass is already empty.\n";
        }
        else {
            volume_ -= 0.1;
            cout << "You open a bottle and make a tiny sip.\n";
        }
    }
    void change_base() {
        cout << "Please, choose the basic ingredient:\n";
        option_print(bases, amount_of_bases, 1);
        int t;
        cin >> t;
        if (!(1 <= t <= amount_of_bases)) {
            throw invalid_argument("There're no such a base in our basement.");
        }
        else {
            remove_ingredient(bases[type_].description);
            type_ = t;
            ingredients_.push_back(bases[type_].description);
            volume_ += 0.3;
            cout << "You added " << bases[type_].description << " into your cattle. Now you have different potion.\n";
        }
    }
};
