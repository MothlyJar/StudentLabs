#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>
#include <string>
#include <QRegularExpressionMatch>
#include <QRegularExpression>
#include "../L6/ext/json/json.hpp"
using js= nlohmann::json;

int row_r = 1;
int row_w = 1;
std::string path_to_file;
QRegularExpression str_e("[А-ЯA-Z][а-яa-z]{1,}/[А-ЯA-Z][а-яa-z]{0,}");
QRegularExpression uint_e("[1-9]\\d{0,}");
QRegularExpression float_e("[1-9]\\d{0,}.\\d{1,}");
QBrush red(QColor(255, 0, 0), Qt::SolidPattern);

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

void MainWindow::on_pushButton_clicked()
{
    path_to_file = QFileDialog::getOpenFileName(this, "Выберите .json файл","/home","*.json").toStdString();
    std::ifstream file(path_to_file);
    js all_data = js::array();
    while(!file.eof()){
        std::string s;
        std::getline(file, s);
        if (!s.empty()) {
            all_data.emplace_back(js::parse(s));
        }

    }
    qInfo() << all_data.size();

    for (int i = 0; i < all_data.size(); ++i) {
        bool all_normal = true;
        bool normal[6] = {true, true, true, true, true, true};

        js data = all_data[i];
        QString name = QString::fromStdString(data["name"].get<std::string>());
        QString desc = QString::fromStdString(data["desc"].get<std::string>());
        QString legs = QString::fromStdString(data["legs"].get<std::string>());
        QString hands = QString::fromStdString(data["hands"].get<std::string>());
        QString drawers = QString::fromStdString(data["drawers"].get<std::string>());
        QString cost = QString::fromStdString(data["cost"].get<std::string>());

        if (!(str_e.match(name).hasMatch()))
            normal[0] = false;
        if (!(str_e.match(desc).hasMatch()))
            normal[1] = false;
        if (!(uint_e.match(legs).hasMatch()))
            normal[2] = false;
        if (!(uint_e.match(hands).hasMatch()))
            normal[3] = false;
        if (!(uint_e.match(drawers).hasMatch()))
            normal[4] = false;
        if (!(float_e.match(cost).hasMatch()))
            normal[5] = false;
        for (int b = 0; b < 6; b++) {
            if (normal[b] == false) {
                all_normal = false;
                break;
            }
        }

        QTableWidgetItem* i_name = new QTableWidgetItem(name);
        QTableWidgetItem* i_desc = new QTableWidgetItem(desc);
        QTableWidgetItem* i_legs = new QTableWidgetItem(legs);
        QTableWidgetItem* i_hands = new QTableWidgetItem(hands);
        QTableWidgetItem* i_drawers = new QTableWidgetItem(drawers);
        QTableWidgetItem* i_cost = new QTableWidgetItem(cost);

        if (all_normal) {
            ui->right->setItem(row_r, 0, i_name);
            ui->right->setItem(row_r, 1, i_desc);
            ui->right->setItem(row_r, 2, i_legs);
            ui->right->setItem(row_r, 3, i_hands);
            ui->right->setItem(row_r, 4, i_drawers);
            ui->right->setItem(row_r, 5, i_cost);
            row_r++;
        }
        else {
            ui->wrong->setItem(row_w, 0, i_name);
            ui->wrong->setItem(row_w, 1, i_desc);
            ui->wrong->setItem(row_w, 2, i_legs);
            ui->wrong->setItem(row_w, 3, i_hands);
            ui->wrong->setItem(row_w, 4, i_drawers);
            ui->wrong->setItem(row_w, 5, i_cost);

            // for (int b = 0; b < 6; b++) {
            //     if (normal[b] == false) {
            //         ui->wrong->item(row_w, b)->setBackground(red);
            //     }
            // }
            row_w++;
        }
    }
}

