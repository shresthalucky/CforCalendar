#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include "functions.h"

HANDLE handle1, handle2;

int eDate[100][3], lines=0;

void locate(int x, int y){
    COORD p = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void add(){
    addEvent();
}

void search(){
    listDate();
    printf("\n\t%d dates found with events.\n\n", lines);

    if(lines!=0){
        char opt;
        for(int i=0; i<lines; i++){
            printf("\t%d %d %d\n", eDate[i][0], eDate[i][1], eDate[i][2]);
        }
        printf("\n");

        do{
            printf("\t[a] View Event\n\t[b] Edit Event\n\t[c] Delete Event\n\n");
            opt = getch();
            if(opt=='a' || opt=='b' || opt=='c')
                break;
        }
        while(1);

        //system("cls");

        switch(opt){
        case 'a':
            eventDetail();
            break;
        case 'b':
            editEvent();
            break;
        case 'c':
            deleteEvent();
            break;
        case 27:
            main();
            break;
        }
    }
    else{
        printf("Please add event first.");
    }
}

void listDate(){
    lines = 0;
    FILE *dateFile;

    dateFile = fopen("./data/datefile", "rb");

    if(dateFile==NULL){
        return;
    }

    int g = 0;
    while(!feof(dateFile)){
        if(fgetc(dateFile)=='\n'){
            lines++;
        }
    }
    rewind(dateFile);
    while(!feof(dateFile)){
        int j=0;
        fscanf(dateFile, "%d %d %d\n", &eDate[g][j], &eDate[g][j+1], &eDate[g][j+2]);
        g++;
    }

    fclose(dateFile);
}


bool pin(int y, int m, int d){
    int i;
    for(i=0; i<lines; i++){
        if((eDate[i][0] == y) && (eDate[i][1] == m) && (eDate[i][2] == d)){
            return true;
        }
    }
    return false;
}
