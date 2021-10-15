#include "main.h"

#include <algorithm>
#include <string>
#include <vector>

using std::vector;
using std::string;

/* create delay in qt */
void delay();
/* filling array with random number */
void updateArray();
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

  // create an instance of QApplication
  QApplication app(argc, argv);
  // creating an instance of GUI
  QWidget window;
  window.resize(200, 100);
  window.setWindowTitle("Sort Algorithm");

  // create layout inside window
  QGridLayout *layout = new QGridLayout(&window);

  window.show();
  return app.exec();
}
