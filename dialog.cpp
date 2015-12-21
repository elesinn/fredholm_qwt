#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{

}

void Dialog::on_comboBox_activated(const QString &arg1)
{

}

void Dialog::on_lineEdit_delta_textChanged(const QString &arg1)
{
    double res = ui->lineEdit_delta->text().toDouble()/ui->lineEdit_alpha->text().toDouble();

    ui->label_6->setText(QString::number(res));
}

void Dialog::on_lineEdit_alpha_textChanged(const QString &arg1)
{
    double res = ui->lineEdit_delta->text().toDouble()/ui->lineEdit_alpha->text().toDouble();
    ui->label_6->setText(QString::number(res));    
}
