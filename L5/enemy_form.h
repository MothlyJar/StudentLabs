#ifndef ENEMY_FORM_H
#define ENEMY_FORM_H
#include <QTreeWidgetItem>
#include <QDialog>
//#include <mainwindow.h>
class MainWindow;
namespace Ui {
class enemy_form;
}

class enemy_form : public QDialog
{
    Q_OBJECT

public:
    int row_;
    QTreeWidgetItem* item_;
    MainWindow* mw_;
    explicit enemy_form(QWidget *parent = nullptr);
    enemy_form(QString name_, QString armor_d, int health, QString rareness, int row,  QTreeWidgetItem* item, MainWindow* mw);
    ~enemy_form();

private slots:
    void on_print_pB_clicked();

    void on_exit_pB_clicked();

private:
    Ui::enemy_form *ui;
};



#endif // ENEMY_FORM_H
