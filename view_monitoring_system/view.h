#pragma once

#include "../controller/controller.h"
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui {
class view;
}
QT_END_NAMESPACE

class view : public QMainWindow {
  Q_OBJECT

public:
  view(QWidget *parent = nullptr);
  ~view();

private slots:
  void on_start_clicked();

private:
  Ui::view *ui;
  s21::Controller *controller = nullptr;
};

