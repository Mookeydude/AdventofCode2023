#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZERO "zero"
#define one "one"
#define TWO "two"
#define THREE "three"
#define FOUR "four"
#define FIVE "five"
#define SIX "six"
#define SEVEN "seven"
#define EIGHT "eight"
#define NINE "nine"

int findword(char* numword){
    if(strstr(numword, "zero")){
        return -1;
    }
    else if (strstr(numword, one)) {
        return 1;
    }
    else if (strstr(numword, TWO)) {
        return 2;
    }
    else if (strstr(numword, THREE)) {
        return 3;
    }
    else if (strstr(numword, FOUR)) {
        return 4;
    }
    else if (strstr(numword, FIVE)) {
        return 5;
    }
    else if (strstr(numword, SIX)) {
        return 6;
    }
    else if (strstr(numword, SEVEN)) {
        return 7;
    }
    else if (strstr(numword, EIGHT)) {
        return 8;
    }
    else if (strstr(numword, NINE)) {
        return 9;
    }
    else{
        return -1;
    }
}
int main(){

    FILE *fptr;
    fptr = fopen("Input.txt", "r");
    char c;
    int sum = 0;
    int tens = -1;
    int ones = -1;
    int i = -1;
    int j = -1;
    int k = -1;
    char* numword;
    numword = malloc(512);
    if(fptr == NULL){
        printf("why U dumb :(\n");
        return 0;
    }
    else {
        printf("U Smart :)\n");
    }
    while (c != EOF){
        c = getc(fptr);
        //printf("%c", c);
        if ((c >=48) && (c <= 57)){
            //array[i] = (c-48);
            if(tens <= 0){
                tens = (c-48);
            }
            else{
                ones = (c-48);
            }
            //printf("%d\n", c);
            strcpy(numword, "");
            j = -1;
        }
        else if(c == 10){
            if(ones < 0){
                sum = sum + ((tens * 10) + tens);
            }
                else{
                    sum = sum + ((tens * 10) + ones);
                }
            //printf("")
           printf("%d%d", tens, ones);
            printf(" %d\n", sum);
        tens = -1;
        ones = -1;
        strcpy(numword, "");
       // numword = NULL;
        i++;
        }
        else if(((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90))){
            strncat(numword, &c, 1);
            printf("%s\n", numword);
            //j = findword(numword);
            //printf("%d\n", findword(numword));
            if (findword(numword) > 0) {
                k = (strlen(numword)-1);
                //printf("%d\n", findword(numword));
                if((tens < 0)&&(findword(numword)>0)){
                    tens = findword(numword);
                }
                else{
                    ones = findword(numword);
                }
                j = findword(numword);
                    //if((j == 1)||(j == 2) || (j == 3) || (j == 5) || (j ==9) || (j == 7)){
                    //k = k - 1;
                //}
                    memmove(numword, numword+k, strlen(numword));
                    k = -1;
                    j = -1;
            }
        }
        else {
            strcpy(numword, "");
        }
        //printf("%d%d\n", tens, ones);
    }

    fclose(fptr);
    printf(" %d\n", sum);

    return 0;
}
