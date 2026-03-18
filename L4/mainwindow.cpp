#include "mainwindow.h"
#include "./ui_mainwindow.h"

//#include "Ticket.hpp"


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


void MainWindow::on_save_pB_clicked()
{
    std::string number = ui->ticketNum_lE->text().toStdString();
    std::string date = ui->dateEdit->text().toStdString();
    std::string prize = ui->prize_lE->text().toStdString();
    if (number.empty() || date.empty() || prize.empty()) {
        ui->exeptions->setText("Not enough data.");
    }
    bool resultL = ui->result_lose_rB->isChecked();
    bool resultW = ui->result_win_rB->isChecked();
    std::string result;
    if (resultL == resultW) {
        ui->exeptions->setText("No result's data.");
    }
    else if (resultL){
        result = "Lose";
    }
    else {
        result = "Win";
    }
    bool requirement_gift = ui->require_gift_cB->isChecked();
    bool requirement_juridical = ui->require_juridicalOnly_cB->isChecked();
    bool requirement_personalVisit = ui->require_personalVisit_cB->isChecked();

}




void MainWindow::on_reset_pB_clicked()
{
    ui->ticketNum_lE->clear();
    ui->dateEdit->clear();
    ui->name_lE->clear();
    ui->prize_lE->clear();
    ui->require_gift_cB->setChecked(false);
    ui->require_juridicalOnly_cB->setChecked(false);
    ui->require_personalVisit_cB->setChecked(false);
    ui->exeptions->clear();
    ui->result_win_rB->setAutoExclusive(false);
    ui->result_lose_rB->setAutoExclusive(false);
    ui->result_win_rB->setChecked(false);
    ui->result_lose_rB->setChecked(false);
    ui->result_win_rB->setAutoExclusive(true);
    ui->result_lose_rB->setAutoExclusive(true);


}

