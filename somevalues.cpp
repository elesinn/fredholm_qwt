#include "somevalues.h"
#include "ui_somevalues.h"

SomeValues::SomeValues(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SomeValues)
{
    ui->setupUi(this);
}

SomeValues::~SomeValues()
{
    delete ui;
}
