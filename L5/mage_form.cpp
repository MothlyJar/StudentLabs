#include "mage_form.h"
#include "ui_mage_form.h"
#include <qmainwindow.h>

mage_form::mage_form(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mage_form)
{
    ui->setupUi(this);
}

mage_form::~mage_form()
{
    delete ui;
}

void mage_form::on_buttonBox_accepted()
{
    close();
}

