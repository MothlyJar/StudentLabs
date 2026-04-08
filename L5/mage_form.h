#ifndef MAGE_FORM_H
#define MAGE_FORM_H
#include "ui_mage_form.h"
#include <QTreeWidgetItem>
//#include <mainwindow.h>
#include <QDialog>
class MainWindow;
namespace Ui {
class mage_form;
}

class mage_form : public QDialog
{
    Q_OBJECT

public:
    int row_;
    QTreeWidgetItem* item_;
    MainWindow* mw_;
    explicit mage_form(QWidget *parent = nullptr);
    mage_form(QString name, int mana, QString element, int health, int row,  QTreeWidgetItem* item, MainWindow* mw);
    ~mage_form();

private slots:
    void on_print_pB_clicked();

    void on_exit_pB_clicked();

private:
    Ui::mage_form *ui;
};

#endif // MAGE_FORM_H
