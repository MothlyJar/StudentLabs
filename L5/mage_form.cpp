#include "mage_form.h"
#include "ui_mage_form.h"
#include <mainwindow.h>
//#include <characters.h>

mage_form::mage_form(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mage_form)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
}
mage_form::mage_form(QString name, int mana, QString element, int health, int row, QTreeWidgetItem* item, MainWindow* mw): ui(new Ui::mage_form) {
        ui->setupUi(this);
        row_ = row;
        item_ = item;
        mw_ = mw;
        ui->name->setText(name);
        ui->mana->setText(QString::number(mana));
        ui->element->setText(element);
        ui->hp->setText(QString::number(health));
        if (element == "Огонь") {
            ui->element->setStyleSheet("color: rgb(245, 181, 44)");
        }
        else if (element == "Вода") {
            ui->element->setStyleSheet("color: rgb(46, 109, 245)");
        }
        else if (element == "Земля") {
            ui->element->setStyleSheet("color: rgb(77, 37, 2)");
        }

        this->setAttribute(Qt::WA_DeleteOnClose);
}
mage_form::~mage_form()
{
    delete ui;
}


void mage_form::on_print_pB_clicked()
{
    qInfo() << "hey";
    mw_->characters.erase(mw_->characters.begin() + row_);
    delete item_;
    this->close();

}


void mage_form::on_exit_pB_clicked()
{
    qInfo() << "hey2";
    this->close();

}

