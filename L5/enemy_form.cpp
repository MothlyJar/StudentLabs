#include "enemy_form.h"
#include "ui_enemy_form.h"

enemy_form::enemy_form(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::enemy_form)
{
    ui->setupUi(this);
}

enemy_form::~enemy_form()
{
    delete ui;
}
