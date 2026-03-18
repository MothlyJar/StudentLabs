#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>

void line_print(int index_start, int index_end) {
    for (int i = index_start; i <= index_end; i++) {
        std::cout << i << ' ' << char(i) << std::endl;
    }
}
void alphabet_print() {
    std::cout << "------\n";
    line_print(39, 90);
    line_print(-64, -1);
    std::cout << "------\n";
}
std::string sort_string(std::string s) {
    const int len = s.length();
    std::string letters = s;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            //std::cout << letters[j] << '.';
            if (letters[i] > letters[j]) {
                std::swap(letters[i], letters[j]);
            }
        }
    }
    //std::cout << s << ' ' << letters << std::endl;
    return letters;
}
std::string lower_case(std::string& word) {
    if (word[0] >= 'а' && word[0] <= 'я') { return word; }
    if (word[0] == 'Ё') {
        word[0] = 'ё';
    }
    if (word[0] >= 'А' && word[0] <= 'П') {
        word[0] = char(word[0] + 32);
    }
    if (word[0] >= 'Р' && word[0] <= 'Я') {
        word[0] = char(word[0] + 80);
    };
    return word;
}
char gl[] = { 'а', 'А', 'е', 'Е', 'ё', 'Ё', 'и', 'И', 'о', 'О', 'у', 'У', 'ъ', 'Ъ', 'ы', 'Ы', 'Э', 'э', 'Ю', 'ю', 'Я', 'я', 'ь', 'Ь' };

int main() {
    std::setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    alphabet_print();

    std::ifstream text("text.txt");
    if (!text.is_open()) {
        std::cout << "Smth's wrong, file isn't open"; return -1;
    }

    // pt 1
    /*
    const int syll = 100;
    char r_text[syll] = {};
     for (int i = 0; i <=syll; i++) {
         char t;
         short f = 0;
         text >> t;
         for(int j = 0; j <=24; j++) {
             if (t == gl[j]) {
                 f = 1;
                 continue;
             }
         }
         if (f == 0) {
             r_text[i] = t;
         }
     }
     for (int i = 0; i <=syll - 1; i++) {
         std::cout << r_text[i];
     }
     */

     //pt 2
    size_t iden = 0;
    std::ifstream text_leniden("text.txt");
    std::string t;
    while (!text_leniden.eof()) {
        
        text_leniden >> t;
        iden++;
    }
    std::string* ra_text = new std::string[iden];
    size_t length = 0;
    while (!text.eof()) {
        text >> ra_text[length];
        length++;
    }
    for (int i = 0; i <= length - 1; ++i) { // áà ¢­ïâì ¯¥à¢ë¥ ¡ãª¢ë
        ra_text[i] = lower_case(ra_text[i]);
    }
    size_t iden2 = 0;
    std::string* words = new std::string[length];
    for (int i = 0; i <= length - 1; i++) {// ®â¡®à á®àâ¨à®¢ ­­ëå ¨ á«®¢, á­®á §­ ª  -
        if (i == 0 && ra_text[i][0] == '-') {
            ra_text[i].erase(0, 1);
        }
        if (ra_text[i] == sort_string(ra_text[i])) {
            words[iden2] = ra_text[i];
            iden2++;
        }
    }
    //std::cout << '3' << iden2;
    for (int i = 0; i < iden2; i++) {
        for (int j = i + 1; j <= iden2; ++j) {
            if (words[i] == words[j]) {
                words[j] = "";
            }
        }
    }

    // á«®¢  á '-' ¢ á¥à¥¤¨­¥ ¨«¨ ®ª ­ç¨¢ îé¨¥áï ­  æ¨äàë ­¥ ¯à®å®¤ïâ ¢ «î¡®¬ á«ãç ¥, 
    // ¢¥¤ì ®­¨ ­¥ ¢¯¨èãâáï ¢ ãá«®¢¨¥  «ä ¢¨â­®£® ¯®àï¤ª , ¯®íâ®¬ã ®â¤¥«ì­® ¨å ¬®¦­® ­¥ ¯à®¢¥àïâì
    for (int i = 0; i <= iden2 - 1; ++i) { // á®àâ¨à®¢ª  ¯® ¤«¨­¥
        for (int j = i + 1; j <= iden2; ++j) {
            if (words[i].length() < words[j].length()) {
                std::swap(words[i], words[j]);
            }
        }
    }
    std::ifstream amount("input.txt");
    int N;
    std::string Nstr;
    amount >> Nstr;
    N = std::stoi(Nstr);
    std::ofstream output("result.txt");
    for (int i = 0; (i < N) && (i < iden2); ++i) {
        output << words[i] << ' ';
    }
    
    text.close();
    delete[] words;
    delete[] ra_text;

    //////////////////// 


    return 0;
}
