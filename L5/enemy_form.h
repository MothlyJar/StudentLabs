#ifndef ENEMY_FORM_H
#define ENEMY_FORM_H

#include <QDialog>

namespace Ui {
class enemy_form;
}

class enemy_form : public QDialog
{
    Q_OBJECT

public:
    explicit enemy_form(QWidget *parent = nullptr);
    ~enemy_form();

private:
    Ui::enemy_form *ui;
};

#endif // ENEMY_FORM_H
