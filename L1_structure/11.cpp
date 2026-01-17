#include <iostream>
#include <string>
using namespace std; 

struct Potion {
        public:
            void set_price(int price) {
                if(price < 0) {
                    throw invalid_argument("Price is less than 0");
                }
                price_ = price;
            } 
            void change_base(string base) {
                cin >> base_;
            }
            void drink() {
                cout << "You open a tiny bottle and make a tiny sip. Potion is warm. Tastes like herbal tea with additional citrus and cinnamon flavour.";
            }
            string return_label() const {return label_;}
            string return_description() const {return description_;}
            float return_volume() const {return volume_;}
            int return_price() const {return price_;}
            void get_base() const {cout << "Brewed with " + base_ + " as basic liquid.\n";}
            void get_info() const {
                cout << return_label() << '\n' << return_description() << '\n';
                get_base();
                cout << "V: " << return_volume() << "\nC: " << return_price() << '\n';
            }
        private:
            string label_ = "Strange potion of healing, probably";
            string description_ = "A tiny glass bottle with bright red liquid and flower petals soaked in it.";
            string base_ = "water";
            float volume_ = 0.3;
            int price_ = 10;
    };

int main() {

    Potion Resist;
    cout << Resist.return_price() << '\n';
    Resist.set_price(120);
    Resist.get_info();
    Resist.change_base("orange juice");
    Resist.get_base();
    Resist.drink();
    return 1;
}