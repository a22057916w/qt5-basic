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

  // connect(sender, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed()));
  QObject::connect(btn, &QPushButton::clicked, [=](){ btn->setText("Fuck You!");});

  // show the application
  window.show();
  return app.exec();
}
