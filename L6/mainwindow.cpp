#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fstream"
#include <QFileDialog>
#include "ext/json/json.hpp"
using js= nlohmann::json;
#include <QRegularExpression>
#include <QRegularExpressionMatch>



void furniture(std::string name, std::string desc, std::string legs, std::string hands, std::string drawers, std::string cost) {
    js all_data = js::array();
    std::fstream file("file.json");
    js data = {
        {"name", name},
        {"desc", desc},
        {"legs", legs},
        {"hands", hands},
        {"drawers", drawers},
        {"cost", cost}
    };
    all_data = js::parse(file);
    all_data.emplace_back(data);
    file << all_data.dump(4);
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
    std::string path_to_file;
    path_to_file = QFileDialog::getOpenFileName(this, "Выберите .txt файл","/home","*.txt").toStdString();
    std::ifstream input(path_to_file);
    std::string rs;
    std::getline(input, rs);
    QString s = QString::fromStdString(rs);
    qInfo() << s;
    if (s.isEmpty()) {
        ui->info->setText("Empty file");
    }
    else {
        QStringList values = s.split("/",Qt::SkipEmptyParts);
        QString name;
        QString desc;
        QString legs;
        QString hands;
        QString drawers;
        QString cost;
        for(int variable_i = 0; variable_i < 6; ++variable_i) {
            switch (variable_i) {
            case 0: name = values[variable_i]; break;
            case 1: desc = values[variable_i]; break;
            case 2: legs = values[variable_i]; break;
            case 3: hands = values[variable_i]; break;
            case 4: drawers = values[variable_i]; break;
            case 5: cost = values[variable_i]; break;
            }
        }
        ui->name_le->setText(name);
        ui->desc_le->setText(desc);
        ui->legs_le->setText(legs);
        ui->hands_le->setText(hands);
        ui->drawers_le->setText(drawers);
        ui->cost_le->setText(cost);
        ui->info->setText("Checked");
    }
}
