#include <stdbool.h>

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// define functions prototypes here
void calendar();
void search();
void add();
int StartSpace();
int leapyear();
void printCal();
void changeMonth(char temp);

void getDateFile();
void addEvent();
void eventDetail();
void listDate();
bool pin(int y, int m, int d);

#endif
