#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{
    ui->txbLogger->setReadOnly(true);
    ui->txbLogger->appendPlainText("--- Action Log ---");
}


void Dialog::on_btnCreateChessboard_clicked()
{
    Board *board = new Board(); 
    ui->txbLogger->appendPlainText("["+ QDateTime().currentDateTime().toString("HH:mm") +"] Board open");
    board->exec();
    ui->txbLogger->appendPlainText(board->getActionLog());
}

void Dialog::on_buttonBox_accepted()
{
    accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}
