#include "Potion.hpp"
#include <iostream>
using namespace std;


int main() {
    try {
        ptn::Potion N("a", "aaa", { "b","c" }, 6, 0.6, 6);
        ptn::Potion D("b", "bbb", { "v","w" }, 2, 0.3, 4);
        //(N + D).print_info();
        //(N += D).print_info();
        (N*D).print_info();
    }
    catch (exception& ex) {
        cout << ex.what();
    }
    catch(...) {
        cout << "Unhandled exception";
    }
    return 0;
}
