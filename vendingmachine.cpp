#include "vendingmachine.h"
#include "ui_vendingmachine.h"
#include <QMessageBox>

VendingMachine::VendingMachine(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VendingMachine)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

VendingMachine::~VendingMachine()
{
    delete ui;
}

void VendingMachine::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
}
void VendingMachine::checkItem(int money){
    if (money >= 100){
        ui->pbCoffee->setEnabled(true);
    }
    if (money >= 150){
        ui->pbTea->setEnabled(true);
    }
    if (money >= 200){
        ui->pbMilk->setEnabled(true);
    }
    if (money < 100){
        ui->pbCoffee->setEnabled(false);
    }
    if (money < 150){
        ui->pbTea->setEnabled(false);
    }
    if (money < 200){
        ui->pbMilk->setEnabled(false);
    }
}
int money = 0;
void VendingMachine::on_pb10_clicked()
{
    changeMoney(10);
    checkItem(money);
}
void VendingMachine::on_pb50_clicked()
{
    changeMoney(50);
    checkItem(money);
}
void VendingMachine::on_pb100_clicked()
{
    changeMoney(100);
    checkItem(money);
}
void VendingMachine::on_pb500_clicked()
{
    changeMoney(500);
    checkItem(money);
}

void VendingMachine::on_pbCoffee_clicked()
{
    changeMoney(-100);
    checkItem(money);
}

void VendingMachine::on_pbTea_clicked()
{
    changeMoney(-150);
    checkItem(money);
}

void VendingMachine::on_pbMilk_clicked()
{
    changeMoney(-200);
    checkItem(money);
}

void VendingMachine::on_pbReset_clicked()
{
    QMessageBox m;
    QString status = QString("%1 return").arg(money);
    m.information(nullptr, "hi", status);
}
