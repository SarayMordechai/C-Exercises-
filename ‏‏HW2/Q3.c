#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
 
void ReverseArray(char* str, int length){
/* Recursive function to reverse a given string*/
    char temp;
    if(length < strlen(str)/2)
    {
        return;
    }
    ReverseArray(str, length-1);
    temp = str[strlen(str)-1 - length];
    str[strlen(str)-1 - length] = str[length];
    str[length] = temp;
}

void InsertLength(char* str, int x){
    /*Recursive function that gets a sentence and replace every space with the sign that equal to the length*/
    char len = strlen(str); 
    
    if(x == len){
        return;
    }
    if(str[x] == ' '){
        str[x] = len;
    }
    InsertLength(str, ++x);
}

/*Only for tests*/
int main(){
    int Length, size=8;
/*Send a string to the function and print the reverse string*/  
    char str[] = "12345678";
      /* Calculate length of the array ( Number of elements)*/
    Length = strlen(str);
    
    /*Checks that the entered size match the actual size*/
    if(Length != size){
        printf("The entered size does not match the array actual size\n");
    }
    else{
    ReverseArray(str, 8);
    printf("Reverse of the given string is %s \n", str);
    }

/*Prints the string with the ascii value of the length instead of spaces*/
    char str1[]= "The book is on the table , and the table is red";
    InsertLength(str1,0);
    printf("%s" , str1);
    return 0;
}