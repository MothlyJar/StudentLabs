#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
//#include <characters.h>
#include <QTreeWidgetItem>
#include <QMainWindow>
class Characters;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::vector<Characters*> characters;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Load_pB_clicked();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
