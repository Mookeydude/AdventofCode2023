#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE* fptr = fopen("input.txt", "r");
    int lines = 0;
    int j = 0;
    int length = 0;
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
    int array[j][lines];
    int i = 0;
    int k = 0;
    c = NULL;
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
return 0;
}
