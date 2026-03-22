#include "ticket.h"
#include <fstream>

Ticket::Ticket(QString number, QString date, QString prize, QString name, QString result, bool requirement_gift, bool requirement_juridical, bool requirement_personalVisit) {
    number_ = number;
    date_ = date;
    prize_ = prize;
    result_ = result;
    name_ = name;
    requirement_gift_ = requirement_gift;
    requirement_juridical_ = requirement_juridical;
    requirement_personalVisit_ = requirement_personalVisit;
}
void Ticket::write_to_file(){
    std::ofstream Output("result.txt", std::ios::app);
    Output << "- - - - -\nНомер билета:" << number_.toStdString() <<
        "\nДата: " << date_.toStdString() <<
        "\nПриз: " << prize_.toStdString() <<
        "\nИмя: " << name_.toStdString() <<
        "\nРезультат: " << result_.toStdString() <<
        "\nПодарок/ Для юр. лица/ Личное присутствие: " << requirement_gift_ << ' ' << requirement_juridical_ << ' ' << requirement_personalVisit_ << "\n- - - - - ";
    Output.close();
}
