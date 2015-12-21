#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_dialog.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    double getAlpha()
    {
        QString tmp= ui->lineEdit_alpha->text();
        double alpha= tmp.toDouble();
        return alpha;
    }

    double getA()
    {
        QString tmp1 = ui->lineEdit_a->text();
        double tmp = ui->lineEdit_a->text().toDouble();
        return tmp;
    }

    double getB()
    {
        return ui->lineEdit_b->text().toDouble();
    }

    double getDelta()
    {
        return ui->lineEdit_delta->text().toDouble();
    }

    int getNumb()
    {
        return ui->comboBox->currentIndex();
    }

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_activated(const QString &arg1);

    void on_lineEdit_delta_textChanged(const QString &arg1);

    void on_lineEdit_alpha_textChanged(const QString &arg1);

public:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
