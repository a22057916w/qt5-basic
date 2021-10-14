/*
Class Doc:
QPushButton: https://doc.qt.io/qt-5/qpushbutton.html
QString : https://doc.qt.io/qt-5.15/qstring.html
QGridLayout: https://doc.qt.io/qt-5.15/qgridlayout.html#addWidget-1
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
  QGridLayout *grid = new QGridLayout();

  for(int row = 0; row < 3; row++) {
    for(int col = 0; col < 3; col++) {
      string val = "(row = " + std::to_string(row) + "col = " + std::to_string(col)  + ")";

      // QPushButton(QString *text) -> QString(const char *)
      // conver c++ string to char* with Null Terminal by function c_str()
      QPushButton *btn = new QPushButton(val.c_str());

      // addWidget(*widget row column rowspan colspan)
      grid->addWidget(btn, row, col, 1, 1);
    }
  }
  // adding grid layout to menu
  window.setLayout(grid);
  window.show();
  return app.exec();
}
