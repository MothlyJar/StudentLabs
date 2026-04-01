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
    ui->exceptions->clear();
    path_to_file = QFileDialog::getOpenFileName(this, "Выберите .txt файл","/home","*.txt");
    if (path_to_file.isEmpty()) {
        ui->exceptions->setText("Нет ссылки на файл загрузки.");
    }
    else {
        std::vector<std::string> lines;
        std::ifstream file(path_to_file.toStdString());
        while (!file.eof()) {
            std::string s;
            getline(file,s);
            lines.emplace_back(s);
        }
        int amount_of_lines = lines.size();
        for (int line_i = 0; line_i < amount_of_lines - 1; line_i++) {
            char identify; std::string name; std::string additional_str; int additional_int; int health; Armor armor;
            std::string current_line = lines[line_i];
            identify = current_line[0];
            current_line.erase(0,2);

            name = current_line.substr(0,current_line.find_first_of(' '));
            current_line.erase(0,current_line.find_first_of(' ')+1);
            additional_str = current_line.substr(0,current_line.find_first_of(' '));
            current_line.erase(0,current_line.find_first_of(' ')+1);
            additional_int = std::stoi(current_line.substr(0,current_line.find_first_of(' ')));
            current_line.erase(0,current_line.find_first_of(' ')+1);
            health = std::stoi(current_line.substr(0,current_line.find_first_of(' ')));
            current_line.erase(0,current_line.find_first_of(' ')+1);
            armor.helmet = std::stoi(current_line.substr(0,current_line.find_first_of(' ')));
            current_line.erase(0,current_line.find_first_of(' ')+1);
            armor.chestplate = std::stoi(current_line.substr(0,current_line.find_first_of(' ')));
            current_line.erase(0,current_line.find_first_of(' ')+1);
            armor.boots = std::stoi(current_line.substr(0,current_line.find_first_of(' ')));

            if (identify == '1') {
                Characters* Current_character = new MageChara(name,health,armor,additional_str,additional_int);
                characters.emplace_back(Current_character);
            }
            else if (identify == '0') {
                Characters* Current_character = new EnemyChara (name,health,armor,additional_str,additional_int);
                characters.emplace_back(Current_character);
            }
            else {
                ui->exceptions->setText("Неопознанный идентификатор.");
                continue;
            }


            QStringList item_data_lt = (QStringList() << QString("%1").arg(name) << QString("%1").arg(additional_str) << QString("%1").arg(additional_int) << QString("%1").arg(health) << QString("<%1/%2/%3>").arg(armor.helmet, armor.chestplate,armor.boots));
            QTreeWidgetItem item_data_tree(item_data_lt);
            QTreeWidgetItem* item_data_tree_p = new QTreeWidgetItem;
            *item_data_tree_p = item_data_tree;
            ui->treeWidget->addTopLevelItem(item_data_tree_p);


        }
        file.close();
    }

}


