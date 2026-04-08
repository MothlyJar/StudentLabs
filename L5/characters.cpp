#include "characters.h"
#include <qdialog.h>
#include <enemy_form.h>
#include <mage_form.h>
#include <ui_mage_form.h>
#include <ui_enemy_form.h>

int MageChara::Craft(int row,  QTreeWidgetItem* item, MainWindow* mw) {
    mage_form* form = new mage_form(name_,mana_,element_,health_, row, item, mw);
    return form->exec();
}

int EnemyChara::Craft(int row,  QTreeWidgetItem* item, MainWindow* mw) {
    QString armor_d = QString("<%1/%2/%3>").arg(armor_.helmet).arg(armor_.chestplate).arg(armor_.boots);
    enemy_form* form = new enemy_form(name_, armor_d, health_, rareness_, row,item, mw);
    return form->exec();
}
