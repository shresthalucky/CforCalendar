#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "functions.h"

int year, startspace, month;
int monthDays[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char *months[] =
{
    " ",
    "\n\t  January",
    "\n\t  February",
    "\n\t  March",
    "\n\t  April",
    "\n\t  May",
    "\n\t  June",
    "\n\t  July",
    "\n\t  August",
    "\n\t  September",
    "\n\t  October",
    "\n\t  November",
    "\n\t  December"
};

void calendar(){
    locate(10, 5);
    printf("Input year and month (YYYY MM) : \t");
    scanf("%d %d", &year, &month);
    startspace = StartSpace();
    leapyear();
    locate(10, 8);
    printCal();
    printf("\n");
}

//To Check The Leap Year
int leapyear(){
    if ((year%4 == 0 && year%100 != 0) || year%100 == 0){
        monthDays[2] = 29;
    }
    else{
        monthDays[2] = 28;
    }
    return (((year % 4 == 0 ) && (year % 100 != 0))) || (year % 400 == 0);
}

// To determine the number of spaces to print at beginning of month(Zeller's Algorithm)
int StartSpace(){
    int d1, d2, d3;
    d1 = (year - 1)/4;
    d2 = (year - 1 )/100;
    d3 = (year - 1)/400;
    startspace = (year + d1 -d2 + d3)%7;
    return (startspace);
}

// Prints Calendar
void printCal(){
    system("cls");
    listDate();

    char temp;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    //get current local date
    int nowYear = t->tm_year+1900;
    int nowMonth = t->tm_mon+1;
    int nowDay = t->tm_mday;

    int day,i;
    for (i=1; i<month; i++){
        startspace = ( startspace + monthDays[i] ) % 7;
    }

    printf("%s %d", months[month], year);
    printf(KGRN "\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" RESET);

    // To Correct the position for the first date
    for (day = 1; day <= 1 + startspace * 5; day++){
        printf(" ");
    }

    // Prints all the dates for one month
    for (day = 1; day <= monthDays[month]; day++){

        if((pin(year, month, day))==true){
            printf(KMAG "%2d" RESET, day);
        }
        else{
            if(year == nowYear && month == nowMonth && day == nowDay){
                printf(KYEL "%2d" RESET, day);
            }
            else if(!((day + startspace) % 7 > 0)){
                printf(KRED "%2d" RESET, day);
            }
            else{
                printf("%2d", day);
            }
        }

        // Checks if the previous day is Sat. Else start Sun in new line.
        if ((day + startspace) % 7 > 0){
            printf("   ");
        }
        else{
            printf("\n ");
        }
    }
    do{
        printf("\n\n [p]\tPrevious Month\n [n]\tNext Month\n[esc]\tBack\n [j]\tJump to month\n [q]\tQuit\n");
        temp = getch();
        if(temp=='p' || temp=='q' || temp=='n' || temp == 'j' || temp == 27) break;
    }while(1);
    changeMonth(temp);

}

void changeMonth(char temp){
    switch (temp){
    case ('q') :
        exit(EXIT_SUCCESS);
    case ('n') :
        month += 1;
        if (month > 12){
            year += 1;
            month = 1;
            leapyear();
            StartSpace();
            printCal();
        }
        else{
            StartSpace();
            printCal();
        }
        break;
    case ('p') :
        month -= 1;
        if (month < 1){
            year -= 1;
            month = 12;
            leapyear();
            StartSpace();
            printCal();
        }
        else{
            StartSpace();
            printCal();
        }
        break;
    case 'j':
        system("cls");
        calendar();
    break;
    case 27 :
        main();
        break;
    default :
        printCal();
    }
}
