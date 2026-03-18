#pragma once
#include <string>
#include <fstream>

class Ticket {
private:
    std::string number_;
    std::string date_;
    std::string prize_;
    std::string result_;
    bool requirement_gift_;
    bool requirement_juridical_;
    bool requirement_personalVisit_;
public:
    Ticket(std::string number, std::string date, std::string prize, std::string result, bool requirement_gift, bool requirement_juridical, bool requirement_personalVisit);
    void write_to_file(){
        std::ofstream resultT("result.txt");
        resultT << "- - - - -\n" << number_ << '\n' << date_ << '\n' << prize_ << '\n' << result_ << '\n' << requirement_gift_ << ' ' << requirement_juridical_ << ' ' << requirement_personalVisit_ << "\n- - - - -";
        resultT.close();
    }
};
