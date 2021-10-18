/*
Document:
QT Style Sheet: https://doc.qt.io/qt-5/stylesheet-examples.html
QObject::tr(): https://doc.qt.io/qt-5/i18n-source-translation.html
QCoreApplication::processEvents: https://doc.qt.io/qt-5/qcoreapplication.html#processEvents
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
void delay() {
  QTime dieTime = QTime::currentTime().addMSecs(SLEEP_ms);
  while(QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
/* filling array with random number */
void updateArray(vector<int> &arr) {
  for(auto& e : arr)
    e = rand() % 100;
}

void updateButton(QPushButton *button[], vector<int> &arr) {
  for(int i = 0; i < arr.size(); i++) {
    string name = std::to_string(arr[i]);
    button[i]->setText(name.c_str());
  }
}

void highlightButton(QPushButton *button) {
  button->setStyleSheet("color:blue; background-color:yellow; font-weight:bold;");
}
/* set the button to normal color */
void unhighlightButton(QPushButton *button) {
  button->setStyleSheet("font-weight:bold;");
}
/* setup button */
void setButtonVal(QPushButton *button, int val) {
  button->setText(std::to_string(val).c_str());
  button->setStyleSheet("color:red; background-color:yellow; font-weight:bold;");
}
/* run bubble sort and update UI */
void bubblesort(vector<int> arr, QPushButton *button[]) {
  for(int i = 0; i < arr.size(); i++) {
    bool swapped = false;
    for(int j = 0; j < arr.size() - 1; j++) {
      highlightButton(button[j]);
      highlightButton(button[j + 1]);
      delay();
      if(arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j+1]);
        setButtonVal(button[j], arr[j]);
        setButtonVal(button[j+ 1], arr[j + 1]);
        delay();
        swapped = true;
      }
      unhighlightButton(button[j]);
      unhighlightButton(button[j + 1]);
    }
    // if no swapping had occoured then list is sorted
    if (!swapped)
      break;
  }
}
/* run selection sort and update UI */
void selectionsort(vector<int> arr, QPushButton *button[]) {
  for(int i = 0; i < arr.size(); i++)
    for(int j = i + 1; j < arr.size(); j++)
      if(arr[i] > arr[j])
        std::swap(arr[i], arr[j]);
}

int main(int argc, char *argv[]) {

  bool isSorting = false;
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
  QPushButton *buttons[arr.size()];
  for(int i = 0; i < arr.size(); i++) {
    string btnVal = std::to_string(arr[i]);
    buttons[i] = new QPushButton(btnVal.c_str());
    buttons[i]->setStyleSheet("font-weight:bold;");
    layout->addWidget(buttons[i], 0, i, 1, 1);
  }

  // the following two functions both work, but tr() can transfer any string to QString
  // which is type of UTF-8. The second one is cathing char * that is already UTF-8
  QRadioButton *radioBubble = new QRadioButton(QObject::tr("Bubble Sort"));
  QRadioButton *radioSelection = new QRadioButton("Selection Sort");
  radioBubble->setChecked(true);
  layout->addWidget(radioBubble, 3, 0, 1, 1);
  layout->addWidget(radioSelection, 3, 1, 1, 1);

  // setup reset and sort button
  QPushButton *btnReset = new QPushButton("Reset");
  btnReset->setStyleSheet("color:red; font-weight:bold;");
  layout->addWidget(btnReset, 3, 8, 1, 1);

  QPushButton *btnSort = new QPushButton("Sort");
  btnSort->setStyleSheet("color:green; font-weight:bold;");
  layout->addWidget(btnSort, 3, 9, 1, 1);

  // when reset button is pressed
  QObject::connect(btnReset, &QPushButton::clicked, [&](){
    // when reset button is pressed generate another random set of array
    // and update it in GUI
    updateArray(arr);
    updateButton(buttons, arr);
    btnSort->setText("Sort");
  });

  // when sort button is pressed
  QObject::connect(btnSort, &QPushButton::clicked, [&](){
    if(isSorting) {
      return;
    }
    isSorting = true;
    btnReset->setVisible(false);
    btnSort->setText("Sorting...");
    // if bubble sort radio button is clicked do binary sort
    // else do selection sort
    radioBubble->isChecked() ? bubblesort(arr, buttons) : selectionsort(arr, buttons);
    btnReset->setVisible(true);
    btnSort->setText("Sort");
    isSorting = false;
  });

  window.show();
  return app.exec();
}
