#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main()
{

    system("cls"); // Clears The Screen

    printf("\nC FOR CALENDAR\n");

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char buffer[80];

    strftime(buffer, 80, "%A, %b %d, %Y | %I:%M %p", t); // format current datetime ( Monday, June 15, 2009 | 1:45:30 PM )
    printf("\n%s\n\n", buffer); // display formatted datetime

    char opt[1];
    int temp;

    do
    {
        printf("Main Menu:\n1.Calendar\n2.Search\n3.Add\n5.Exit\n");
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
