#include "Potion.hpp"
using namespace std;


int main() {

    try {
        Potion N("", "aaa", { "b","c" }, 6, 0.6, 6);
        //Potion D("b", "bbb", { "v","w" }, 2, 0.3, 4);
        //(N + D).print_info();
        //(N += D).print_info();
        //(N*D).print_info();
    }
    catch (exception ex) {
        cout << ex.what();
    }
    return 0;
}
