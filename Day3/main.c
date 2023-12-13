#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int STOD(char* number){
int sum = 0;

for(int i = strlen(number); i>0; i--){
//printf("%d\n", number[strlen(number)])
sum = sum +((number[strlen(number)-i]-48) * (pow(10, i-1)));
}
return sum;
}

int returnnum(char *line, int space){
char * string = " ";
int numstart = 0;
int numend = 0;
int cursor = space;

if(numstart < 1){
    if((cursor == 0) || (line[cursor - 1] == '.')){
        numstart = 1;
    }
    else if(numend < 1){
        if(line[cursor] == '.'){
            numend = 1;
        }
        else{
            strncat(string, &line[cursor], 1);
            line[cursor] = '.';
            cursor++;
        }
    }
}


return STOD (string);
}


int main(){

    FILE* fptr = fopen("input.txt", "r");
    int lines = 0;
    int j = 0;
    int length = 0;
    int sum = 0;
    char c;
    while(c != EOF){
        length++;
        //printf("%c %d\n", c, length);
        c = getc(fptr);
        if(c == '\n'){
            lines++;
            j = length;
            length = 0;
        }
    }
    fseek(fptr, 0, SEEK_SET);
    //printf("# of lines:%d, length of lines %d\n", lines, j);
    char array[j][lines];
    int i = 0;
    int k = 0;
    while(c!= EOF){
        c= getc(fptr);
        array[i][k] = c;
        if(c == '\n'){
            k++;
            i = 0;
            continue;
        }
        i++;
    }
    i = 0;
    /*for(int m = 0; m < lines; m++){
        i = 0;
        while(i<j){
            printf("%c", array[i][m]);
            i++;
        }
    }*/
    for(int n = 0; n <= lines; n++){
        for(int i = 0; i< j; i++){
            if((array[i][n] != '.') && (array[i][n] >= 48) && (array[i][n] <= 67)){
                sum = sum + returnnum(&array[0][lines], i);
            }
            
        }
        }
return 0;
}
