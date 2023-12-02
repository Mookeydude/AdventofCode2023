#include "main.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *fptr;
    int array[100][3];
    int c;
    char Line [1000];
    fptr = fopen("Input.txt", "r");

    if(fptr == NULL){
        printf("Y U Stupid :(\n");
        return 0;
    }
    else{
        printf("You good\n");
    }
    //fgets(Line, sizeof(Line), fptr);
    //printf("%s", Line);
     //fgets(Line, sizeof(Line), fptr);
    //printf("%s", Line);
    while(getc(fptr) != EOF){
        fgets(Line, sizeof(Line), fptr);
        printf("%s", Line);
    }
return 0;
}
