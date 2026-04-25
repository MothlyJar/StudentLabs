#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fstream"
#include "ext/json/json.hpp"
using js= nlohmann::json;
#include <QRegularExpression>
#include <QRegularExpressionMatch>


// qstr qstr uint uint uint float
QRegularExpression type("[А-ЯA-Z][а-яa-z]{1,}/[А-ЯA-Z][а-яa-z]{0,}/[1-9]\\d{0,}/[1-9]\\d{0,}/[1-9]\\d{0,}/[1-9]\\d{0,}.\\d{1,}");

void furniture(std::string name, std::string desc, std::string legs, std::string hands, std::string drawers, std::string cost) {
    std::ofstream right("right.json", std::ios::app);
    std::ofstream wrong("wrong.json", std::ios::app);
    QString data_check = QString("%1/%2/%3/%4/%5/%6").arg(name, desc, legs, hands, drawers, cost);
    js data = {
        {"name", name},
        {"desc", desc},
        {"legs", legs},
        {"hands", hands},
        {"drawers", drawers},
        {"cost", cost}
    };
    if (type.match(data_check).hasMatch()) {
        right << data;
        right << '\n';
        qInfo() << "right";
    }
    else {
        wrong << data;
        wrong << '\n';
        qInfo() << "wrong";
    }
}

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

void MainWindow::on_ok_clicked()
{
    std::string name = ui->name_le->text().toStdString();
    std::string desc = ui->desc_le->text().toStdString();
    std::string legs = ui->legs_le->text().toStdString();
    std::string hands = ui->hands_le->text().toStdString();
    std::string drawers = ui->drawers_le->text().toStdString();
    std::string cost = ui->cost_le->text().toStdString();
    furniture(name, desc, legs, hands, drawers, cost);
    ui->info->setText("Checked");
}


void MainWindow::on_browse_clicked()
{
    std::ifstream input("input.json");
    js data = js::parse(input);
    std::string name = data["name"].get<std::string>();
    std::string desc = data["desc"].get<std::string>();
    std::string legs = data["legs"].get<std::string>();
    std::string hands = data["hands"].get<std::string>();
    std::string drawers = data["drawers"].get<std::string>();
    std::string cost = data["cost"].get<std::string>();
    furniture(name, desc, legs, hands, drawers, cost);
    ui->info->setText("Checked");
}
