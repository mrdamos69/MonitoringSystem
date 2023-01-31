#pragma once

#include "../controller/controller.h"
#include <QMainWindow>
#include <QStandardItemModel>

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

private:
  Ui::view *ui;
  QStandardItemModel *new_table;
  s21::Controller *controller = nullptr;
};

