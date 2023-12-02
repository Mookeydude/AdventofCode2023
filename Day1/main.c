#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fptr;
    fptr = fopen("Input.txt", "r");
    int c;
    int array[1000];
    int sum = 0;
    int tens = -1;
    int ones = -1;
    int i = -1;
    if(fptr == NULL){
        printf("why U dumb :(\n");
        return 0;
    }
    else {
        printf("U Smart :)\n");
    }

    while (c != EOF){
        c = getc(fptr);
        printf("%c", c);
        if ((c >=48) && (c <= 57)){
            //array[i] = (c-48);
            if(tens < 0){
                tens = (c-48);
            }
            else{
                ones = (c-48);
            }
            //printf("%d\n", c);
        }
        else if(c == 10){
            if(ones < 0){
                sum = sum + ((tens * 10) + tens);
            }
                else{
                    sum = sum + ((tens * 10) + ones);
                }
            printf(" %d\n", sum);
        tens = -1;
        ones = -1;
        i++;
        }
    }

    fclose(fptr);
    printf("%d\n", sum);

    return 0;
}
