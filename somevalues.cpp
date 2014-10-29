#include "somevalues.h"
#include "ui_somevalues.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
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

void SomeValues::setValue(QVector<double> s,QVector<double> z0, QVector<double> newZ)
{
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;

    QStringList horizontalHeader;
    horizontalHeader.append("s");
    horizontalHeader.append("Z0(s)");
    horizontalHeader.append("Z*(s)");

    model->setHorizontalHeaderLabels(horizontalHeader);

    QString tmpS;
    QString tmpZ0;
    QString tmpNewZ;
    for(int i=0;i<s.size();i++)
    {
        tmpS=QString::number(s[i]);
        item = new QStandardItem(tmpS);
        model->setItem(i,0,item);
    }
    for(int i=0;i<s.size();i++)
    {
        tmpZ0=QString::number(z0[i]);
        item = new QStandardItem(tmpZ0);
        model->setItem(i,1,item);
    }

    for(int i=0;i<s.size();i++)
    {
        tmpNewZ=QString::number(newZ[i]);
        item = new QStandardItem(tmpNewZ);
        model->setItem(i,2,item);
    }

    ui->tableView->setModel(model);
}

void SomeValues::saveAsTXT(QString filename)
{

    QFile f(filename);

    if( f.open( QIODevice::WriteOnly ) )
    {
        QTextStream ts( &f );
        QStringList strList;
        for( int r = 0; r < ui->tableView->verticalHeader()->count(); ++r )
        {
            strList.clear();
            for( int c =0; c < ui->tableView->horizontalHeader()->count(); ++c )
            {
                strList <<ui->tableView->model()->data(ui->tableView->model()->index(r, c), Qt::DisplayRole).toString();
            }
            ts << strList.join( "\t" )+"\n";
        }
        f.close();
    }
}

void SomeValues::on_pushButton_clicked()
{
    QString str = QFileDialog::getSaveFileName(0, "Save as", "", "");
    saveAsTXT(str);
}
