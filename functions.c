#include <stdio.h>
#include "functions.h"
#include <stdbool.h>

void add()
{
    addEvent();
}

void search()
{
    eventDetail();
}

int eDate[100][3];

void listDate()
{
    FILE *dateFile;

    dateFile = fopen("./data/datefile", "rb");
    int g = 0;
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
    for(i=0; i<100; i++)
    {
        if((eDate[i][0] == y) && (eDate[i][1] == m) && (eDate[i][2] == d))
        {
            return true;
        }
    }
    return false;
}
