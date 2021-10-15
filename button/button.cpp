/*
Document
QObject::connect: https://doc.qt.io/qt-5/qobject.html#connect-2
*/
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QtWidgets>
#include <string>

using std::string;

int main(int argc, char *argv[]) {
  // Creating instance of QApplication
  QApplication app(argc, argv);

  // Creating instance of GUI
  QWidget window;
  QPushButton *btn = new QPushButton("click me!", &window);

  // QObject::connect(const QObject *sender, const char *signal, const char *method)
  QObject::connect(btn, &QPushButton::clicked, [=](){ btn->setText("Fuck You!");});

  // show the application
  window.show();
  return app.exec();
}
