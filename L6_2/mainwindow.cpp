#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>
#include <string>
#include <QRegularExpressionMatch>
#include <QRegularExpression>
#include "../L6/ext/json/json.hpp"
#include "../L6/data_s.h"
#include <vector>
#include <QTreeWidgetItem>
using js= nlohmann::json;

std::vector<data_s> right_data;
std::vector<data_s> wrong_data;

std::string path_to_file;
QRegularExpression str_e("[А-ЯA-Zа-яa-z]{1,}");
QRegularExpression uint_e("[1-9]\\d{0,}");
QRegularExpression float_e("[1-9]\\d{0,}.\\d{1,}");
QBrush red(QColor(255, 0, 0, 150), Qt::SolidPattern);

// int compare(data_s* a, data_s* b) {
//     if(a->_data["name"].get<std::string>() > b->_data["name"].get<std::string>()) {
//         return 1;
//     }
//     else if (a->_data["name"].get<std::string>() < b->_data["name"].get<std::string>()) {
//         return -1;
//     }
//     else {
//         return 0;
//     }
// }

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->right->header()->resizeSection(0,80);
    ui->right->header()->resizeSection(1,80);
    ui->right->header()->resizeSection(2,30);
    ui->right->header()->resizeSection(3,30);
    ui->right->header()->resizeSection(4,30);
    ui->right->header()->resizeSection(5,60);

    ui->wrong->header()->resizeSection(0,80);
    ui->wrong->header()->resizeSection(1,80);
    ui->wrong->header()->resizeSection(2,30);
    ui->wrong->header()->resizeSection(3,30);
    ui->wrong->header()->resizeSection(4,30);
    ui->wrong->header()->resizeSection(5,60);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    path_to_file = QFileDialog::getOpenFileName(this, "Выберите .json файл","/home","*.json").toStdString();
    std::ifstream file(path_to_file);

    js data_r = js::parse(file);

    qInfo() << data_r.size();

    for (const auto& data_e : data_r) {
        QStringList data_l;
        QString name = QString::fromStdString(data_e["name"].get<std::string>());
        QString desc = QString::fromStdString(data_e["desc"].get<std::string>());
        QString legs = QString::fromStdString(data_e["legs"].get<std::string>());
        QString hands = QString::fromStdString(data_e["hands"].get<std::string>());
        QString drawers = QString::fromStdString(data_e["drawers"].get<std::string>());
        QString cost = QString::fromStdString(data_e["cost"].get<std::string>());
        data_l << name << desc << legs << hands << drawers << cost;

        QTreeWidgetItem* item = new QTreeWidgetItem(data_l);

        data_s data = data_s(name.toStdString(), desc.toStdString(), legs.toStdString(), hands.toStdString(), drawers.toStdString(), cost.toStdString(), item);

        if (!(str_e.match(name).hasMatch()))
            data.normal[0] = false;
        if (!(str_e.match(desc).hasMatch()))
            data.normal[1] = false;
        if (!(uint_e.match(legs).hasMatch()))
            data.normal[2] = false;
        if (!(uint_e.match(hands).hasMatch()))
            data.normal[3] = false;
        if (!(uint_e.match(drawers).hasMatch()))
            data.normal[4] = false;
        if (!(float_e.match(cost).hasMatch()))
            data.normal[5] = false;
        for (int b = 0; b < 6; b++) {
            if (data.normal[b] == false) {
                data.all_normal = false;
                break;
            }
        }

        for (const bool& b : data.normal) {
            qInfo() << b;
        }
        qInfo() << data.all_normal;

        if (data.all_normal){
            right_data.emplace_back(data);
        }
        else {
            wrong_data.emplace_back(data);
        }
        qInfo() << "data added to vector\n";
    }

    for (int i = 0; i < right_data.size() - 1; ++i) {
        for (int j = i + 1; j < right_data.size(); ++j) {
            if (right_data[i]._data["name"].get<std::string>() < right_data[j]._data["name"].get<std::string>())
                std::swap(right_data[i],right_data[j]);
        }
    }
    for (int i = 0; i < wrong_data.size() - 1; ++i) {
        for (int j = i + 1; j < wrong_data.size(); ++j) {
            if (wrong_data[i]._data["name"].get<std::string>() < wrong_data[j]._data["name"].get<std::string>())
                std::swap(wrong_data[i],wrong_data[j]);
        }
    }

    qInfo() << "sorted";

    for (const auto& data: right_data){
        ui->right->addTopLevelItem(data._item);
    }
    for (const auto& data: wrong_data){
        ui->wrong->addTopLevelItem(data._item);
        for (int i = 0; i < 6; ++i) {
            if (!data.normal[i]) {
                data._item->setBackground(i, red);
            }
        }
    }
    qInfo() << "added to table";
}

