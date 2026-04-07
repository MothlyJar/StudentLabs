#include "characters.h"
#include <qdialog.h>
#include <ui_mage_form.h>
#include <ui_enemy_form.h>

int MageChara::Craft() {
    QDialog* form = new QDialog();
    Ui_mage_form ui;
    ui.setupUi(form);
    ui.name->setText(name_);
    ui.mana->setText(QString::number(mana_));
    ui.element->setText(element_);
    ui.hp->setText(QString::number(health_));
    if (element_ == "Огонь") {
        ui.element->setStyleSheet("color: rgb(245, 181, 44)");
    }
    else if (element_ == "Вода") {
        ui.element->setStyleSheet("color: rgb(46, 109, 245)");
    }
    else if (element_ == "Земля") {
        ui.element->setStyleSheet("color: rgb(77, 37, 2)");
    }
    return form->exec();
}

int EnemyChara::Craft() {
    QDialog* form = new QDialog();
    Ui_enemy_form ui;
    QString armor_d = QString("<%1/%2/%3>").arg(armor_.helmet).arg(armor_.chestplate).arg(armor_.boots);
    ui.setupUi(form);
    ui.armor->setText(armor_d);
    ui.name->setText(name_);
    ui.hp->setText(QString::number(health_));
    if (rareness_ == "Обычный") {
        ui.name->setStyleSheet("color: rgb(79, 166, 36)");
    }
    else if (rareness_ == "Редкий") {
        ui.name->setStyleSheet("color: rgb(46, 109, 245)");
    }
    else if (rareness_ == "Легендарный") {
        ui.name->setStyleSheet("color: rgb(245, 181, 44)");
    }
    return form->exec();
}
