#include "characters.h"
#include <qdialog.h>
#include <ui_mage_form.h>
int  MageChara::Craft() {
    QDialog* form = new QDialog();
    Ui_mage_form ui;
    ui.setupUi(form);
    ui.name->setText(name_);
    ui.element->setText(element_);
    ui.hp->setText(QString::number(health_));
    return form->exec();
}

int EnemyChara::Craft() {

}
