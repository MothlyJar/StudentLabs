#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QFileDialog>
#include <characters.h>
#include <QTreeWidgetItem>

QString path_to_file;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->header()->resizeSection(0,200);
    ui->treeWidget->header()->resizeSection(1,200);
    ui->treeWidget->header()->resizeSection(2,30);
    ui->treeWidget->header()->resizeSection(3,30);
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
        QFile file(path_to_file);
        file.open(QIODevice::ReadOnly);
        while (true) {
            QString current_line = file.readLine().trimmed();
            if(current_line.isEmpty()){
                break;
            }
            //qInfo() << current_line;
            int identify; QString name; QString additional_str; int additional_int; int health; Armor armor;
            current_line.remove(' ');
            QStringList values = current_line.split(",",Qt::SkipEmptyParts);
            //qInfo() << values;
            /*name = current_line.substr(0,current_line.find_first_of(' '));
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
        armor.boots = std::stoi(current_line.substr(0,current_line.find_first_of(' ')));*/
        for(int variable_i = 0; variable_i < 8; ++variable_i) {
                switch (variable_i) {
                case 0: identify = values[variable_i].toInt(); break;
                case 1: name = values[variable_i];break;
                case 2: additional_str = values[variable_i]; break;
                case 3: additional_int = values[variable_i].toInt(); break;
                case 4: health = values[variable_i].toInt(); break;
                case 5: armor.helmet = values[variable_i].toInt(); break;
                case 6: armor.chestplate = values[variable_i].toInt(); break;
                case 7: armor.boots = values[variable_i].toInt(); break;
            }
        }
            //qInfo() << identify << ' ' << name << ' ' << additional_str << ' ' << additional_int << ' ' << health << ' ' << armor.helmet << ' ' << armor.chestplate << ' ' << armor.boots;
            if (identify == 1) {
                //qInfo() << "Mage created";
                Characters* Current_character = new MageChara(name,health,armor,additional_str,additional_int);
                characters.emplace_back(Current_character);
            }
            else if (identify == 0) {
                //() << "Enemy created";
                Characters* Current_character = new EnemyChara (name,health,armor,additional_str,additional_int);
                characters.emplace_back(Current_character);
            }
            else {
                ui->exceptions->setText("Неопознанный идентификатор.");
                continue;
            }
            values.remove(0,1);
            QString armor_line = QString("<%1/%2/%3>").arg(armor.helmet).arg(armor.chestplate).arg(armor.boots);
            values.pop_back();
            values.pop_back();
            values.pop_back();
            values.emplace_back(armor_line);
            QTreeWidgetItem item_data_tree(values);
            QTreeWidgetItem* item_data_tree_p = new QTreeWidgetItem;
            *item_data_tree_p = item_data_tree;
            ui->treeWidget->addTopLevelItem(item_data_tree_p);

        }
        file.close();
    }
}


void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column) {
    int row = ui->treeWidget->indexFromItem(item).row();
    characters[row]->Craft(row, item,this);
}

