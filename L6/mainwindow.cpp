#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fstream"
#include <QFileDialog>
#include "ext/json/json.hpp"
#include "data_s.h"
using js= nlohmann::json;

js all_data;

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

    data_s data = data_s(name, desc, legs, hands, drawers, cost, nullptr);
    data.q_total_info();
    data.data_export("file.json", "file.json", all_data);

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
    //qInfo() << s;
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
