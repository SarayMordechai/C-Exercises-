#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ReorderArray(char* arr, int size){
    /*A function that reorder an array by letters then numbers and after that all the other characters */
    int i = 0, count = 0;

    /*For loop that moves all the letters at the beginning of the array*/
    for(i=0; arr[i]; i++){
        if (isalpha(arr[i]))
        {
            char c = arr[count];
            arr[count] =arr[i];
            arr[i] = c;
            count +=1;  
        }
    }

    /*For loop that moves all the digits after the letters*/
    for(i = count; arr[i]; i++){
        if (isdigit(arr[i]))
        {
            char c = arr[count];
            arr[count] =arr[i];
            arr[i] = c;
            count +=1;  
        }
    }
}

/*Only for tests*/
int main(){
    int Length , size = 13;
    char x[] = {'5', 's', '=', 'r', '1', '!', 't', 'T', 'y', '9', '@', '<', '4'};
    
   /* Calculate length of the array ( Number of elements)*/
    Length = strlen(x);
    
    /*Checks that the entered size match the actual size*/
    if(Length != size){
        printf("The entered size does not match the array actual size");
        return 1;
    } 
    ReorderArray(x, size);
    return 0;
}