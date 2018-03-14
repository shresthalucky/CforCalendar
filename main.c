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

    char opt;

    do{
        locate(20, 10);
        printf("[a] View Calendar");
        locate(20, 11);
        printf("[b] Search Events");
        locate(20, 12);
        printf("[c] Add Events");
        locate(20, 13);
        printf("[d] Exit");
        locate(20, 15);
        printf("Enter your option : \t");
        opt = _getch();
        system("cls");
        if(opt >= 'a' || opt <= 'd') break;
    }while(1);    // Asks input until the input is between 0 and 5

    switch (opt){           //Go to user selected option
        case 'a' :
            calendar();
            break;
        case 'b' :
            search();
            break;
        case 'c' :
            add();
            break;
        case 'd' :
            exit(EXIT_SUCCESS);
        default :
            main();
    }
    return 0;
}
