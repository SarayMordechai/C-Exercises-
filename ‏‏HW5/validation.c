#include <stdio.h>
#include <string.h>
#include <math.h>
#include "validation.h"

int string_Length(char* str, int len, char* fieldName){
    /*Validate that the length of the string is not bigger than the max length*/
    if(strlen(str) > len){
        printf("%s cannot be longer than %d characters %s \n", fieldName ,len, str);
        return 1;
    }
    return 0;
}

int only_digits_string_length(char* str, int len, char* fieldName){
    int i = 0;
    /*Check that the length of the string is equal to the given length */
    if(strlen(str) == len){
        /*Check that the string contains only digits*/
        for (i = 0; i < strlen(str); i++){
            if (str[i] < '0' || str[i] > '9'){
                printf("%s need to contain only digits \n", fieldName);
                return 1;
            }
        }    
    }else{
        printf("%s must contain %d digits \n", fieldName ,len);
        return 1;
    }
    return 0;
}

int min_number(int num, int min_num, char* fieldName){
    /*Validate that the given number is not bigger than the max number*/
    if(num < min_num){
        printf("%s cannot be less than %d numbers \n", fieldName, min_num);
        return 1;
    }
    return 0;
} 

int max_number(int num, int max_num, char* fieldName){
    /*Validate that the given number is not bigger than the max number*/
    if(num >= max_num){
        printf("%s cannot be greater than %d numbers \n", fieldName, max_num);
        return 1;
    }
    return 0;
} 

int max_digits(int num, int max_digits, char* fieldName){
    /*Validate that the given numbers does not contain more than a given number of digits*/
    if((floor (log10(num)) + 1) > max_digits){
        printf("%s cannot be longer than %d numbers \n", fieldName ,max_digits);
        return 1;
    }
    return 0;
}

int exact_digits(int num, int max_digits, char* fieldName){
    /*Validate that the given numbers does not contain more than a given number of digits*/
    if((floor (log10(num)) + 1) != max_digits){
        printf("%s have to contain %d numbers \n", fieldName ,max_digits);
        return 1;
    }
    return 0;
}

int array_max(char* arr, int max_len){
    /*Validate that the given array is not bigger than the max number*/
    int size = sizeof(arr)/sizeof(arr[0]);
    if( size > max_len){
        return 1;
    }  
    return 0;  
}

int not_empty_arr(char* arr){
    /*Validate that the given array is not empty*/
    if( arr == NULL) {
        return 1;  
    }
    return 0 ;  
}