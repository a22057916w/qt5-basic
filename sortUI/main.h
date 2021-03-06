#ifndef MAIN_H_
#define MAIN_H_

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QTime>
#include <QThread>
#include <QTextEdit>
#include <QRadioButton>
#include <vector>

using std::vector;

#define SLEEP_ms 500

/* create delay in qt */
void delay();
/* filling array with random number */
void updateArray(vector<int> &arr);
/* set button value corresponding to the updated or sorted array */
void updateButton(QPushButton *button[], vector<int> &arr);
/* set the bkg color of button to yellow */
void highlightButton(QPushButton *button);
/* set the button to normal color */
void unhighlightButton(QPushButton *button);
/* setup button */
void setButtonVal(QPushButton *button, int val);
/* run bubble sort and update UI */
void bubblesort(vector<int> arr, QPushButton *button[]);
/* run selection sort and update UI */
void selectionsort(vector<int> arr, QPushButton *button[]);

#endif /* MAIN_H_ */
