
#include <iostream>
#include <string>
using namespace std;

struct Option { 
    string description;
    int type;
};

void option_print(Option opts[], int n, int start) { 
    for (int i = start; i < n;i++) {
        cout << opts[i].type << ": " << opts[i].description << '\n';
    }
}


class Potion {
private:
    const float relative_zero = 0.001;
    const int amount_of_bases = 8;

    string label_;
    string description_;
    float volume_;
    int price_;
    int type_; 

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
;
public:
    Potion() { //базовый
        label_ = "Untitled";
        description_ = "Empty bottle.";
        volume_ = relative_zero;
        price_ = 0.1;
        type_ = 0;
        cout << "[construct] You took an empty bottle.\n";
    }
    Potion(const Potion& other) { // копирование
        label_ = other.label_;
        description_ = other.description_;
        volume_ = other.volume_;
        price_ = other.price_;
        type_ = other.type_;
        cout << "[construct] You brewed exactly the same potion as before.\n";
    }
    Potion(string label, string descriprion, int type_of_base, float volume, int price) : //полного заполнения
        label_(label), description_(descriprion), volume_(volume), price_(price) { 
        cout << "[construct] You brewed new potion.\n";
    }
    ~Potion() {
        cout << this << "[destruct] Your potion turned sour.";
    }

    void set_price(int price) {
        if (price < 0) {
            throw invalid_argument("Price is less than 0.");
        }
        price_ = price;
    }
    void change_base() {
        cout << "Please, choose the basic ingredient:\n";
        option_print(bases,amount_of_bases,1);
        int t;
        cin >> t;
        if (!(1<=t<=amount_of_bases)) {
            throw invalid_argument("There're no such a base in our basement.");
        }
        else {
            type_ = t;
            volume_ += 0.3;
            cout << "You added " << bases[type_].description << " into your cattle. Now you have different potion.\n";
        }
    }
    void empty_the_glass() {
        if (volume_ <= relative_zero) {
            cout << "The glass is already empty.\n";
        }
        else {
            volume_ = relative_zero;
            type_ = 0;
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

    const string get_label() const { return label_; } // manual value return 
    const string get_description() const { return description_; }
    const float get_volume() const { return volume_; }
    const int get_price() const { return price_; }

    const void print_base() const { // cout included
        if (type_ == 0) {
            cout << "Nothing but an air.\n";
        }
        else {
            cout << "Brewed with " + bases[type_].description + " as basic ingredient.\n"; 
        }
    }
    const void print_info() const {
        cout << get_label() << '\n' << get_description() << '\n';
        print_base();
        cout << "V: " << get_volume() << "\nC: " << get_price() << '\n';
    }
};

int main() {

    try {
        Potion N;
        N.change_base();
        N.print_info();
;
    }
    catch (exception ex) {
        cout << ex.what();
    }
}
