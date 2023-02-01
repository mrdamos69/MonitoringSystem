#include "view.h"
#include "ui_view.h"

view::view(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::view) {
    ui->setupUi(this);
    watcher_file();
}

view::~view() {
    delete ui;
}

//Запуск ядра
void view::on_start_clicked() {
    controller->starting_project();
}

//Слежка файла
void view::watcher_file() {
//Создаем наследника
fsWatcher = new QFileSystemWatcher(this);
//устанавливаем слежку на файл
fsWatcher->addPath("/Users/luigiket/MonitoringSystem/logs.txt");
//Связываем сигнал со слотом, как только файл будет изменен
//произойдет вызов слота changed(QString)
connect(fsWatcher, SIGNAL(fileChanged(QString)), this, SLOT(settext()));
}

//Вывод содержимого файла
void view::settext() {
    std::string output = controller->print_last_strings();
    QByteArray byteArray(output.c_str(), output.length());
    ui->textBrowser->setText(byteArray);
    ui->textBrowser->show();
}

