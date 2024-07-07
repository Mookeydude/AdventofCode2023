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

int returnnum(int space, int line, int length, int lines, char array0[length][lines]){
    char * string;
    string = malloc(16);
int numstart = 0;
int numend = 0;
int cursor = space;

printf("return num executed: %c, %d, %d\n", array0[space][line], space, line);

while((numstart < 1) || (numend < 1)){
    if((cursor == 0) || ((array0[cursor - 1][line] < 48) || (array0[cursor - 1][line] > 57))){
        numstart = 1;
    }
    else{
        cursor--;
    }
    if((numend < 1) && (numstart > 0)){
        if((array0[cursor][line] >= 48) && (array0[cursor][line] <= 57)){
  //          printf("%c, %d, %d\n", array0[cursor][line], cursor, line);
            strncat(string, &array0[cursor][line], 1);
            array0[cursor][line] = '.';
            cursor++;
         //   printf("%c, %d, %d\n", array0[cursor][line], numstart, numend);
        }
        else{
            numend = 1;
        }
    }
}
printf("Part Number: %d\n", STOD(string));
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
        c = getc(fptr);
        //printf("%c %d\n", c, length);
        //c = getc(fptr);
        if(c == '\n'){
            lines++;
            j = length;
            length = 0;
        }
    }
    //fseek(fptr, 0, SEEK_SET);
    fclose(fptr);
    fptr = fopen("input.txt", "r");
    printf("# of lines:%d, length of lines %d\n", lines, j);
    //c = ' ';
    char array[j][lines];
    int i = 0;
    int k = 0;
    c = getc(fptr);
    while(c!= EOF){
        //c = getc(fptr);
      //  printf("%c %d, %d\n", c, i, k);
        array[i][k] = c;
        //c = getc(fptr);
        if(c == '\n'){
            k++;
            i = 0;
        //    continue;
        }
        //array[i][k] = c;
        else{
            i++;
        }
        c = getc(fptr);
    }
    i = 0;
for(int m = 0; m < lines; m++){
        i = 0;
        while(i<j){
            printf("%c", array[i][m]);
            i++;
        }
}

//Part 1

/*    for(int n = 0; n < lines; n++){
        for(int i = 0; i< j; i++){
            if((array[i][n] != '.') && ((array[i][n] < 48) || (array[i][n] > 57)) && (array[i][n] != '\n')){
              //  printf("%c %d, %d\n", array[i][n], i, n);
                if((i < j) && (array[i+1][n] >= 48) && (array[i+1][n] <= 57)){
                //    printf("%d, %d\n", i, n);
                sum = sum + returnnum(i+1, n, j, lines, array);
            }
                if((i > 0) && (array[i-1][n] >= 48) && (array[i-1][n] <= 57)){
                  //  printf("%d, %d\n", i-1, n);
                    sum = sum + returnnum(i-1, n, j, lines, array);
            }
                if((n < lines) &&(array[i][n+1] >= 48) && (array[i][n+1] <= 57)){
                    //printf("%d, %d\n", i, n+1);
                sum = sum + returnnum(i, n+1, j, lines, array);
                }
                if((i < lines) && (n < lines) && (array[i+1][n+1] >= 48) && (array[i+1][n+1] <= 57)){
                    //printf("%d, %d\n", i+1, n+1);
                sum = sum + returnnum(i+1, n+1, j, lines, array);
            }
                 if((i > 0) && (n < lines) && (array[i-1][n+1] >= 48) && (array[i-1][n+1] <= 57)){
 //printf("%d, %d\n", i-1, n+1);
                     sum = sum + returnnum(i-1, n+1, j, lines, array);
            }
                if((n > 0) && (array[i][n-1] >= 48) && (array[i][n-1] <= 57)){
 //printf("%d, %d\n", i, n-1);
                    sum = sum + returnnum(i, n-1, j, lines, array);
                }
                if((i < lines) && (n > 0) && (array[i+1][n-1] >= 48) && (array[i+1][n-1] <= 57)){
 //printf("%d, %d\n", i+1, n-1);
                    sum = sum + returnnum(i+1, n-1, j, lines, array);
                }
                         if((i > 0) && (n > 0) && (array[i-1][n-1] >= 48) && (array[i-1][n-1] <= 57)){
 //printf("%d, %d\n", i-1, n-1);
                             sum = sum + returnnum(i-1, n-1, j, lines, array);
            }
            }

            
        }
        }*/
int product = 1;
int gear = 0;
  for(int n = 0; n < lines; n++){
        for(int i = 0; i< j; i++){
            if(array[i][n] == '*'){
                printf("%c %d, %d\n", array[i][n], i, n);
                if((i < j) && (array[i+1][n] >= 48) && (array[i+1][n] <= 57)){
                 //   printf("%d, %d\n", i, n);
                //sum = sum + returnnum(i+1, n, j, lines, array);
                product = product * returnnum(i+1, n, j, lines, array);
                gear++;
            }
                if((i > 0) && (array[i-1][n] >= 48) && (array[i-1][n] <= 57)){
                  //  printf("%d, %d\n", i-1, n);
                  //  sum = sum + returnnum(i-1, n, j, lines, array);
 product = product * returnnum(i-1, n, j, lines, array);
                    gear++;
            }
                if((n < lines) &&(array[i][n+1] >= 48) && (array[i][n+1] <= 57)){
                    //printf("%d, %d\n", i, n+1);
                //sum = sum + returnnum(i, n+1, j, lines, array);
 product = product * returnnum(i, n+1, j, lines, array);
                    gear++;
                }
                if((i < lines) && (n < lines) && (array[i+1][n+1] >= 48) && (array[i+1][n+1] <= 57)){
                    //printf("%d, %d\n", i+1, n+1);
                //sum = sum + returnnum(i+1, n+1, j, lines, array);
 product = product * returnnum(i+1, n+1, j, lines, array);
                    gear++;
                }
                 if((i > 0) && (n < lines) && (array[i-1][n+1] >= 48) && (array[i-1][n+1] <= 57)){
 //printf("%d, %d\n", i-1, n+1);
                     //sum = sum + returnnum(i-1, n+1, j, lines, array);
 product = product * returnnum(i-1, n+1, j, lines, array);
                     gear++;
                 }
                if((n > 0) && (array[i][n-1] >= 48) && (array[i][n-1] <= 57)){
 //printf("%d, %d\n", i, n-1);
                   // sum = sum + returnnum(i, n-1, j, lines, array);
 product = product * returnnum(i, n-1, j, lines, array);
                    gear++;
                }
                if((i < lines) && (n > 0) && (array[i+1][n-1] >= 48) && (array[i+1][n-1] <= 57)){
 //printf("%d, %d\n", i+1, n-1);
                 //   sum = sum + returnnum(i+1, n-1, j, lines, array);
 product = product * returnnum(i+1, n-1, j, lines, array);
                    gear++;
                }
                         if((i > 0) && (n > 0) && (array[i-1][n-1] >= 48) && (array[i-1][n-1] <= 57)){
 //printf("%d, %d\n", i-1, n-1);
                            // sum = sum + returnnum(i-1, n-1, j, lines, array);
 product = product * returnnum(i-1, n-1, j, lines, array);
                             gear++;
                         }
                         if (gear == 2){
                             sum = sum + product;
                             printf("sum is now:%d\n", sum);
                         }
                         product = 1;
                         gear = 0;
            }


        }
    }
    printf("Total = %d\n", sum);
return 0;
}
