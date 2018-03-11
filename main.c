#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "functions.h"

int main()
{
    char *dir = "data";
    CreateDirectory(dir, NULL);

    system("cls"); // Clears The Screen
    locate(30, 5);
    printf(KCYN "C FOR CALENDAR" RESET);

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char buffer[80];
    locate(20, 7);
    strftime(buffer, 80, "%A, %b %d, %Y | %I:%M %p", t); // format current datetime ( Monday, June 15, 2009 | 1:45:30 PM )
    printf("%s\n\n", buffer); // display formatted datetime

    char opt[1];
    int temp;

    do
    {
        locate(20, 10);
        printf("[1] View Calendar");
        locate(20, 11);
        printf("[2] Search Events");
        locate(20, 12);
        printf("[3] Add Events");
        locate(20, 13);
        printf("[4] Exit");
        locate(20, 15);
        printf("Enter your option : \t");
        scanf("%s", opt);
        temp = atoi(opt);   // Converts string into int
        system("cls");
    }
    while(temp == 0 || ((temp<=0) || (temp>=5)));    // Asks input until the input is between 0 and 5

    switch (temp)           //Go to user selected option
    {
    case 1 :
        calendar();
        break;
    case 2 :
        search();
        break;
    case 3 :
        add();
        break;
    case 4 :
        exit(EXIT_SUCCESS);
    default :
        main();
    }
    return 0;
}
