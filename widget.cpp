#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mg = new DatabaseManager();
    mg->connectDB();

}

Widget::~Widget()
{
    mg->closeDB();
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    mg->getListOfPositions();
    qDebug() << "Wykonalem";
}
