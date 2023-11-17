/*
**
** QWASAR.IO -- my_join
**
** @param {string_array*} param_1
** @param {char*} param_2
**
** @return {char*}
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

char* my_join(string_array* param_1, char* param_2)
{
    //string_array* stringPtr = malloc(sizeof(stringPtr));
    int  i = 0, x = 0, y = 0;
    char *newArr =malloc(sizeof(char)-1);
    while(x <param_1->size ||param_1->size == 0){
        while(param_1->array[x][i] != '\0'){
            newArr[y] = *param_1->array[x]+i;
            i++;
            y++;
        }
        x++; i=0;
       if(x < param_1->size){
            while(param_2[i] != '\0') {
                newArr[y] = param_2[i];
                y++;
                i++;
            }
            i= 0;
        } 
    }
    return newArr;
}
/*
int main(){

    struct s_string_array s= {
        .size = 4,
        .array = (char*[]){"abc", "def", "gh", "!"}
    };

    char *t = "-";

    printf("%s", my_join(&s,t));
    return 0;
}

/*
{
    string_array* stringPtr = malloc(sizeof(stringPtr));
    int  i = 0, x = 0, y = 0;
    char *newArr;
    while(x <param_1->size){
        //printf("x");
        while(i <1){ // param_1->array[x][i] != '\0'
            //printf("%c",param_1->array[x][i]); // YES!
            newArr = param_1->array[x];
            printf("%s", newArr);
            i++;
            y++;
        }
        x++; i=0;
        printf("%c",param_2[i]);
    } */