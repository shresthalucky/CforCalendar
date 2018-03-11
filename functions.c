#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include "functions.h"

HANDLE handle1, handle2;

int eDate[100][3], lines=0;

void locate(int x, int y)
{
    COORD p = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void add()
{
    addEvent();
}

void search()
{
    listDate();
    printf("%d dates found with events.\n", lines);

    if(lines!=0)
    {
        for(int i=0; i<lines; i++)
        {
            printf("%d %d %d\n", eDate[i][0], eDate[i][1], eDate[i][2]);
        }
        printf("\n");
        eventDetail();
    }
    else
    {
        printf("Please add event first.");
    }
}

void listDate()
{
    FILE *dateFile;

    dateFile = fopen("./data/datefile", "rb");

    if(dateFile==NULL)
    {
        return;
    }

    int g = 0;
    while(!feof(dateFile))
    {
        if(fgetc(dateFile)=='\n')
        {
            lines++;
        }
    }
    rewind(dateFile);
    while(!feof(dateFile))
    {
        int j=0;
        fscanf(dateFile, "%d %d %d\n", &eDate[g][j], &eDate[g][j+1], &eDate[g][j+2]);
        g++;
    }

//  for (int k = 0; k < 10; k++) {
//	for (int i = 0; i < 3; i++) {
//	  printf("%d ", eDate[k][i]);
//	}printf("\n");
//  }

    fclose(dateFile);
}


bool pin(int y, int m, int d)
{
    int i;
    for(i=0; i<lines; i++)
    {
        if((eDate[i][0] == y) && (eDate[i][1] == m) && (eDate[i][2] == d))
        {
            return true;
        }
    }
    return false;
}
