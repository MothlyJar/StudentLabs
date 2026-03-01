#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void line_print(int index_start, int index_end) {
    for(int i = index_start; i <= index_end; i++) {
    std::cout << i << ' ' << char(i) << std::endl;
}
}
void alphabet_print() { 
    std::cout << "------\n";
    line_print(39,90);
    line_print(65+32,90+32);
    line_print(128,175);
    line_print(158+66,175+66);
    std::cout << "------\n";
}
char gl[] = {' ', '¥', 'ñ', '¨', '®', 'ã', 'ê', 'ë', 'ì', 'í', 'î', 'ï', '€', '…', 'ð', 'ˆ', 'Ž', '“', 'š', '›', 'œ', '', 'ž', 'Ÿ'};
char sogl[] = {'¡', '¢', '£', '¤', '¦', '§', '©', 'ª', '«', '¬', '­', '¯', 'à', 'á', 'â', 'ä', 'å', 'æ', 'ç', 'è', 'é'};
int main() {
    //alphabet_print();

std::ifstream text("text.txt");

    // pt 1
    //const int syll = 100;
    // if (!text.is_open()) {
    //     std::cout << "Smth's wrong, file isn't open"; return -1;
    // }
    // char r_text[syll] = {syll*'0'};
    // for (int i = 0; i <=syll; i++) {
    //     char t;
    //     short f = 0;
    //     text >> t;
    //     for(int j = 0; j <=24; j++) {
    //         if (t == gl[j]) {
    //             f = 1;
    //             continue;
    //         }
    //     }
    //     if (f == 0) {
    //         r_text[i] = t;
    //     }
    // }
    // for (int i = 0; i <=syll; i++) {
    //     std::cout << r_text[i];
    // }

    //pt 2
    std::ifstream amount("input.txt");
    int N;
    amount >> N; 
    std::vector<std::string> ra_text;
    std::string st;
    while(!text.eof()) {
        text >> st;
        ra_text.emplace_back(st);
    }


    // for (int i = 0; i <= words.size(); i++) {
    //     std::cout << words[i];
    // }
    text.close();
return 0;
}