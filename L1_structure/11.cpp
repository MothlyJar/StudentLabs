
#include <iostream>
#include <string>
using namespace std;

struct Option { //выбор базового ингредиента зелья
    string description;
    int type;
};

void option_print(Option opts[], int n) { //распечатать опции, как в свитче по виду
    for (int i = 0; i < n;i++) {
        cout << opts[i].type << ": " << opts[i].description << '\n';
    }
}


class Potion {
private:
    string label_;
    string description_;
    string base_;
    float volume_;
    int price_;
    int type_; 

    Option bases[7]{
        {"Water", 0},
        {"Orange juice", 1},
        {"Beer",2},
        {"Unicorn's blood",3},
        {"Abyss",4},
        {"Head of Cerberus",5},
        {"Set of unknown mushrooms",6}
    };
public:
    Potion() {
        label_ = "Untitled";
        description_ = "Empty bottle.";
        base_ = "Nothing but an air.";
        volume_ = 0;
        price_ = 0.1;
        type_ = -1;
        cout << "You took an empty bottle.\n";
    }
    Potion(const Potion& other) { // копирование
        label_ = other.label_;
        description_ = other.description_;
        base_ = other.base_;
        volume_ = other.volume_;
        price_ = other.price_;
        type_ = other.type_;
    }
    Potion(string label, string descriprion, int type_of_base, float volume, int price) : //полного заполнения
        label_(label), description_(descriprion), base_(bases[type_of_base].description), volume_(volume), price_(price) { 
        cout << "You brewed new potion.\n";
    }
    ~Potion() {
        cout << this << "destruct";
    }

    void set_price(int price) {
        if (price < 0) {
            throw invalid_argument("Price is less than 0.");
        }
        price_ = price;
    }

    void change_base() {
        cout << "Please, choose the basic ingredient:\n";
        option_print(bases,7);
        cin >> type_;
        base_ = bases[type_].description; // по индексу(типу) выводим, что за база
        volume_ += 0.5;
    }
    //void change_base(string base) { // базовая смена базы через приём аргумента в функции
    //    cout << "You have changed the base.";
    //    base_ = base;
    //    volume_ += 0.5;
    //}

    void drink() {
        if (volume_ > 0) {
            volume_ -= 0.1;
            cout << "You open a bottle and make a tiny sip.";
        }
        else {
            cout << "The glass is already empty.";
        }  
    }

    string get_label() const { return label_; } // manual value return 
    string get_description() const { return description_; }
    float get_volume() const { return volume_; }
    int get_price() const { return price_; }

    void print_base() const { cout << "Brewed with " + base_ + " as basic ingredient.\n"; } // with cout
    void print_info() const {
        cout << get_label() << '\n' << get_description() << '\n';
        print_base();
        cout << "V: " << get_volume() << "\nC: " << get_price() << '\n';
    }
};

int main() {

    try {
        Potion N;

    }
    catch (exception ex) {
        cout << ex.what();
    }
}
