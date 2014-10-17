#ifndef SOMEVALUES_H
#define SOMEVALUES_H

#include <QDialog>

namespace Ui {
class SomeValues;
}

class SomeValues : public QDialog
{
    Q_OBJECT

public:
    explicit SomeValues(QWidget *parent = 0);
    ~SomeValues();

private:
    Ui::SomeValues *ui;
};

#endif // SOMEVALUES_H
