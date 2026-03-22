#ifndef TICKET_H
#define TICKET_H

#include <QString>


class Ticket {
private:
    QString number_;
    QString date_;
    QString prize_;
    QString name_;
    QString result_;
    bool requirement_gift_;
    bool requirement_juridical_;
    bool requirement_personalVisit_;
public:
    Ticket(QString number, QString date, QString prize, QString name, QString result, bool requirement_gift, bool requirement_juridical, bool requirement_personalVisit);
    void write_to_file();
};

#endif // TICKET_H
