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
std::string sort_string(std::string s) {
    const int len = s.length();
    std::vector<char> letters;
    for (int i = 0; i <= len; i++) {
        letters.emplace_back(s[i]);
    }
    for (int i = 0; i <= len - 1; ++i) {
        for (int j = i + 1; j <= len; ++j) {
            if(letters[i] > letters[j]){
                std::swap(letters[i], letters[j]);
            }
        }
    }
    for (int i = 0; i <= len; i++) {
        s[i] = letters[i];
    }
    return s;
}
std::string lover_case(std::string& word) {
    if (word[0] >= 'а' && word[0] <= 'я') { return word;}
    if (word[0] == 'Ё') {
        word[0] = 'ё';
    }
    if (word[0] >= 'А' && word[0] <= 'П') {
        word[0] = char(word[0] + 32);
    }
    if (word[0] >= 'Р' && word[0] <= 'Я') {
        word[0] = char(word[0] + 80);
    };
    return word;
}
char gl[] = {'а', 'е', 'ё', 'и', 'о', 'у', 'ъ', 'ы', 'ь', 'э', 'ю', 'я', 'А', 'Е', 'Ё', 'И', 'О', 'У', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я'};

int main() {
    //alphabet_print();

    std::ifstream text("text.txt");
    if (!text.is_open()) {
        std::cout << "Smth's wrong, file isn't open"; return -1;
    }

    // pt 1

    //const int syll = 100;
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

    std::vector<std::string> ra_text;
    std::string st;
    while(!text.eof()) {
        text >> st;
        ra_text.emplace_back(st);
    }
    std::vector<std::string> words; 
    for (int i = 0; i <= ra_text.size(); i++) {// отбор сортированных и слов, снос знака -
        if (i == 0 && ra_text[i][0] == '-') {
            ra_text[i].erase(0, 1);
        }
        if (ra_text[i] == sort_string(ra_text[i])) {  
            words.emplace_back(ra_text[i]);
        }
    }
    for (int i = 0; i <= words.size() - 1; ++i) { // сравнять первые буквы
        words[i] = lover_case(words[i]);
    }
    for (int i = 0; i <= words.size(); ++i) { //убрать повторки
        for (int j = i + 1; j <= words.size(); ++j) {
            if (words[i] == words[j]) {
                words.erase(words.begin() + i);
            }
        }
    }
    // слова с '-' в середине или оканчивающиеся на цифры не проходят в любом случае, 
    // ведь они не впишутся в условие алфавитного порядка, поэтому отдельно их можно не проверять
    for (int i = 0; i <= words.size() - 1; ++i) { // сортировка по длине
        for (int j = i + 1; j <= words.size(); ++j) {
            if (words[i].length() < words[j].length()){
                std::swap(words[i], words[j]);
            }
        }
    }
    std::ifstream amount("input.txt");
    int N;
    amount >> N; 
    std::ofstream output("result.txt");
    for (int i = 0; i < N; ++i) {
        output << words[i] << ' ';
    }

    text.close();

       //////////////////// 
    for (int i = 0; i <= words.size(); i++) {
        std::cout << words[i] << ' ';
    }

return 0;
}