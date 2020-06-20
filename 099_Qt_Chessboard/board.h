#ifndef BOARD_H
#define BOARD_H

#include <QDialog>
#include <QPainter>
#include <QDateTime>

namespace Ui {
class Board;
}

class Board : public QDialog
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

    QString getActionLog();

private slots:
    void on_btnClose_clicked();

private:
    Ui::Board *ui;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // BOARD_H
