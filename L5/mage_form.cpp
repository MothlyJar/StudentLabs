#include "mage_form.h"
#include "ui_mage_form.h"
#include <mainwindow.h>

mage_form::mage_form(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mage_form)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

mage_form::~mage_form()
{
    delete ui;
}


void mage_form::on_print_pB_clicked()
{
    qInfo() << "hey";
    this->close();

}


void mage_form::on_exit_pB_clicked()
{
    qInfo() << "hey2";
    this->close();

}

