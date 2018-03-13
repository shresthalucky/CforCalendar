#include <stdbool.h>
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\x1B[0m"   //Reset Color

// define functions prototypes here
void locate(int x, int y);
void calendar();
void search();
void add();
int StartSpace();
int leapyear();
void printCal();
void changeMonth(char temp);

void getDateFile();
void addEvent();
void writeEvent();
void eventDetail();
void listDate();
void editEvent();
void deleteEvent();
bool pin(int y, int m, int d);

#endif
