#include <iostream>
#include <Potion.hpp>
#include <Cattle.hpp>
using namespace std;

int main() {
    try {
        ptn::Potion N("a", "aaa", { "b","c" }, 6, 0.6, 6);
        ptn::Potion D("b", "bbb", { "v","w" }, 2, 0.3, 4);
        //(N + D).print_info();
        //(N += D).print_info();
        //ptn::Cattle C;
        ptn::Cattle F("Steel pod", 4, 10, 2, {"Water", "Maple leaves"});
        //C.print_info();
        F.print_info();
        F.empty_the_cattle();
        F.print_info();
    }
    catch (exception& ex) {
        cout << ex.what();
    }
    catch(...) {
        cout << "Unhandled exception";
    }
    return 0;
}
