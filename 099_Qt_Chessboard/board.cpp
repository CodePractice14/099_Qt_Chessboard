#include "board.h"
#include "ui_board.h"

Board::Board(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
}

void Board::on_btnClose_clicked()
{
    accept();
}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *)
{
    int x =0;
    int y = 0;

    int tableWidth = 0;
    int tableHeight = 0;
    bool use_colorBlack = true;
    QPainter painter(this);

    for(int columnIndex = 0; columnIndex < 8; columnIndex++)
    {
        for(int rowIndex = 0; rowIndex < 8; rowIndex++)
        {
            if(use_colorBlack)
            {
                painter.setBrush(Qt::black);
                use_colorBlack = false;
            }
            else
            {
                painter.setBrush(Qt::white);
                use_colorBlack = true;
            }
            QRect rectangle(x, y, 100, 100);
            painter.drawRect(rectangle);
            x += 100;
            tableWidth += 100;
        }
        x = 0; //reset the x axis to get back to the first "column"
        y += 100; //jump the painter to the next "row"
        tableHeight += 100;
        use_colorBlack = !use_colorBlack; //switch to the next color
    }
}


QString Board::getActionLog()
{
    QString actionLog = "["+ QDateTime().currentDateTime().toString("HH:mm") +"] Board closed";
    return actionLog;
}


