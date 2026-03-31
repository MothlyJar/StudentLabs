#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>
#include <vector>
#include "characters.h"

QString path_to_file;
std::vector<Characters*> characters;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Load_pB_clicked()
{
    if (path_to_file.isEmpty()) {
        ui->exceptions->setText("Нет ссылки на файл загрузки.");
    }
    else {
        std::ifstream file(path_to_file.toStdString());
        while (!file.eof()) {
            ui->exceptions->clear();
            int identify; std::string name;
            file >> identify >> name;
            /*bool repeat_f = 0;
            for(Characters* character : characters) {
                if(character->get_name() == name) {
                    repeat_f = 1;
                    break;
                }
            }
            if (repeat_f == 1){
                ui->exceptions->setText("Данные этого (этих) персонажа(жей) уже были выгружены.");
                continue;
            }
            else {*/
                std::string additional_str; int additional_int; int health; Armor armor;
                file >> additional_str >> additional_int >> health >> armor.helmet >> armor.chestplate >> armor.boots;
                if (identify == 0) {
                    Characters* Current_character = new MageChara(name,health,armor,additional_str,additional_int);
                    characters.emplace_back(Current_character);
                }
                else if (identify == 1) {
                    Characters* Current_character = new EnemyChara (name,health,armor,additional_str,additional_int);
                    characters.emplace_back(Current_character);
                }
                else {
                    ui->exceptions->setText("Неопознанный идентификатор.");
                    continue;
                }


                QString item_data_t = QString("%1 %2 %3 %4 <%5/%6/%7>").arg(name,additional_str).arg(additional_int).arg(health).arg(armor.helmet).arg(armor.chestplate).arg(armor.boots);
                QPushButton* item_data_pB = new(QPushButton);
                item_data_pB->setText(item_data_t);
                ui->verticalLayout->addWidget(item_data_pB);
            //}

        }
        file.close();
    }
}


void MainWindow::on_ChooseFile_pB_clicked()
{
        path_to_file = QFileDialog::getOpenFileName(this, "Выберите файл","/home","*.txt");
}

