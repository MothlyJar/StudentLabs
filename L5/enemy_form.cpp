#include "enemy_form.h"
#include "ui_enemy_form.h"
#include <mainwindow.h>
enemy_form::enemy_form(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::enemy_form)
{
    ui->setupUi(this);
}
enemy_form::enemy_form(QString name, QString armor_d, int health, QString rareness,int row,  QTreeWidgetItem* item, MainWindow* mw) :  ui(new Ui::enemy_form){
    ui->setupUi(this);
    row_ = row;
    item_ = item;
    mw_ = mw;
    ui->armor->setText(armor_d);
    ui->name->setText(name);
    ui->hp->setText(QString::number(health));
    if (rareness == "Обычный") {
        ui->name->setStyleSheet("color: rgb(79, 166, 36)");
    }
    else if (rareness == "Редкий") {
        ui->name->setStyleSheet("color: rgb(46, 109, 245)");
    }
    else if (rareness == "Легендарный") {
        ui->name->setStyleSheet("color: rgb(245, 181, 44)");
    }
}
enemy_form::~enemy_form()
{
    delete ui;
}


void enemy_form::on_print_pB_clicked()
{
    qInfo() << "hey";
    mw_->characters.erase(mw_->characters.begin() + row_);
    delete item_;
    this->close();
}


void enemy_form::on_exit_pB_clicked()
{
    qInfo() << "hey2";
    this->close();
}

