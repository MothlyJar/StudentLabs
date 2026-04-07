#ifndef MAGE_FORM_H
#define MAGE_FORM_H
#include "ui_mage_form.h"

#include <QDialog>

namespace Ui {
class mage_form;
}

class mage_form : public QDialog
{
    Q_OBJECT

public:
    explicit mage_form(QWidget *parent = nullptr);
    ~mage_form();

private slots:


    void on_print_pB_clicked();

    void on_exit_pB_clicked();

private:
    Ui::mage_form *ui;
};

#endif // MAGE_FORM_H
