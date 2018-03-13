#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct event
{
    char time[6];
    char location[20];
    char note[100];
} e;

FILE *file;
FILE *dateFile;
int day, month, year;
char f[50], y[4], m[2], d[2], fullDate[15];

// Compares the dates with events to highlight dates
void getDateFile()
{
    char filepath[50] = "./data/";
    printf("Enter Date (YYYY MM DD): ");
    fflush(stdin);
    scanf("%d %d %d", &year, &month, &day);
    // Convert int to string
    itoa(year, y, 10);
    itoa(month, m, 10);
    itoa(day, d, 10);

//  strcat(fullDate, strcat(y, strcat(m, d)));
//  strcat(f, strcat(filepath, fullDate));

    strcat(f, strcat(filepath, strcat(fullDate, strcat(y, strcat(m, d)))));
}

void addEvent()
{

    char check;
    getDateFile();

//  printf("Saved to %s\n", f);

    file = fopen(f, "ab");

    if(file==NULL)
    {
        file = fopen(f, "wb");
    }

    dateFile = fopen("./data/datefile", "ab");

    if(dateFile == NULL)
    {
        dateFile = fopen("./data/datefile", "wb");
    }

    fprintf(dateFile, "%d %d %d\n", year, month, day);
    fclose(dateFile);

    do
    {
        check = 'n';

        fflush(stdin);
        printf("Time: ");
        fgets(e.time, sizeof(e.time), stdin);

        fflush(stdin);
        printf("Location: ");
        fgets(e.location, sizeof(e.location), stdin);

        fflush(stdin);
        printf("Note: ");
        fgets(e.note, sizeof(e.note), stdin);

        fwrite(&e, sizeof(e), 1, file);

        printf("\nEvent successfully saved!\n");
        printf("[a] Main Menu\n[b] Add Another Event\n[c] Quit\nEnter Your Option : ");
        check = getch();
        putchar('\n');
        if(check == 'a'){
                main();
        }else if(check == 'c'){
                exit(EXIT_SUCCESS);
        }
        //scanf("%c", &check);

    }
    while(check == 'b');

    fclose(file);
    getch();
}


void eventDetail()
{

    getDateFile();

    file = fopen(f, "rb");

    if(file==NULL)
    {
        printf("No events found on %s", fullDate);
    }

    while (fread(&e, sizeof(e), 1, file)==1)
    {
        printf("\nTime: %s", e.time);
        printf("\nLocation: %s", e.location);
        printf("\nNote: %s", e.note);
    }

    fclose(file);
    getch();
}
