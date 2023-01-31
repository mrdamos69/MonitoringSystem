#include "view.h"
#include "ui_view.h"

view::view(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::view) {
    ui->setupUi(this);
}

view::~view()
{
    delete ui;
}


void view::on_start_clicked()
{
    controller->starting_project();
    QFile file("/Users/luigiket/MonitoringSystem/logs.txt");
    if (!file.open(QIODevice::ReadWrite))
        QMessageBox::information(0, "info", file.errorString());
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
    ui->textBrowser->move(10,10);
    ui->textBrowser->show();
    file.close();
}

