/*
Document:
QT Style Sheet: https://doc.qt.io/qt-5/stylesheet-examples.html
Using tr() for All Literal Text : https://doc.qt.io/qt-5/i18n-source-translation.html
*/

#include "main.h"

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cout;

/* create delay in qt */
void delay();
/* filling array with random number */
void updateArray(vector<int> &arr) {
  for(auto& e : arr)
    e = rand() % 100;
}
/* set the bkg color of button to yellow */
void highlightButton();
/* set the button to normal color */
void unhighlightButton();
/* setup button */
void setButton();
/* run bubble sort and update UI */
void bubblesort();
/* run selection sort and update UI */
void selectionsort();

int main(int argc, char *argv[]) {

  const int size = 10;
  vector<int> arr(size, 0);

  updateArray(arr);

  // create an instance of QApplication
  QApplication app(argc, argv);
  // creating an instance of GUI
  QWidget window;
  window.resize(200, 100);
  window.setWindowTitle("Sort Algorithm");

  // create layout inside window
  QGridLayout *layout = new QGridLayout(&window);
  QPushButton *button[arr.size()];
  for(int i = 0; i < arr.size(); i++) {
    string btnVal = std::to_string(arr[i]);
    button[i] = new QPushButton(btnVal.c_str());
    button[i]->setStyleSheet("font-weight:bold;");
    layout->addWidget(button[i], 0, i, 1, 1);
  }

  // the following two functions both work, but tr() can transfer any string to QString
  // which is type of UTF-8. The second one is cathing char * that is already UTF-8
  QRadioButton *radioBubble = new QRadioButton(QObject::tr("Bubble Sort"));
  QRadioButton *radioSelection = new QRadioButton("Selection Sort");
  radioBubble->setChecked(true);
  layout->addWidget(radioBubble, 3, 0, 1, 1);
  layout->addWidget(radioSelection, 3, 1, 1, 1);

  // setup reset and sort button

  window.show();
  return app.exec();
}
