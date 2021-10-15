#include "main.h"

#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

using std::vector;
using std::string;

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
  QPushButton *button[arr.size];
  for(int i = 0; i < arr.size(); i++) {
    string btnVal = std::to_string(arr[i]);
    button[i] = new QPushButton(btnVal.c_str());
    button[i]->setStyleSheet("\ font-weight:bold; \");
    layout->addWidget(button[i], 0. i. 1, 1);
  }

  window.show();
  return app.exec();
}
