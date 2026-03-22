#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include <QRegularExpression>

#include "ticket.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegularExpression ticketNum_expr("[1-9]-\\d{5}");
    QRegularExpression prize_expr("[А-ЯA-Z][а-яa-z]{0,}");
    QRegularExpression name_expr("[А-Я][а-я]{1,}");
    QValidator *ticketNum_template  = new QRegularExpressionValidator(ticketNum_expr, this);
    QValidator *prize_template  = new QRegularExpressionValidator(prize_expr, this);
    QValidator *name_template  = new QRegularExpressionValidator(name_expr, this);
    ui->ticketNum_lE->setValidator(ticketNum_template);
    ui->prize_lE->setValidator(prize_template);
    ui->name_lE->setValidator(name_template);
}

MainWindow::~MainWindow()
{
    //delete ui->ticketNum_lE->validator();
    //delete ui->prize_lE->validator();
    //delete ui->name_lE->validator();

    delete ui;

}


void MainWindow::on_save_pB_clicked()
{
    QString number = ui->ticketNum_lE->text();
    QString date = ui->dateEdit->text();
    QString prize = ui->prize_lE->text();
    QString name = ui->name_lE->text();
    bool resultL = ui->result_lose_rB->isChecked();
    bool resultW = ui->result_win_rB->isChecked();
    QString result;
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

    if (number.isEmpty() || date.isEmpty() || prize.isEmpty()) {
        ui->exeptions->setText("Not enough data.");
    }
    else {
        Ticket Data(number, date, prize, name, result, requirement_gift, requirement_juridical, requirement_personalVisit);
        Data.write_to_file();
    }
}



void MainWindow::on_reset_pB_clicked()
{
    ui->ticketNum_lE->clear();
    ui->dateEdit->setDateTime(QDateTime::fromString("16/03/2026","dd/MM/yyyy"));
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

