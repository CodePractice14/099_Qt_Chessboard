#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "board.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void init();

private slots:
    void on_btnCreateChessboard_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
