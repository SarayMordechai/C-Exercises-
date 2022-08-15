#include <stdio.h>
#include <string.h>
#include <math.h>
#include "car.h"
#include "client.h"
#include "supplier.h"
#include "company.h"

int string_Length(char* str, int len){
    /*Validate that the length of the string is not bigger than the max length*/
    if(strlen(str) > len){
        return 1;
    }
    return 0;
}

int max_number(int num, int max_num){
    /*Validate that the given number is not bigger than the max number*/
    if(num > max_num){
        return 1;
    }
    return 0;
}

int max_digits(int num, int max_digits){
    /*Validate that the given numbers does not contain more than a given number of digits*/
    if(num/pow(10,max_digits) !=0){
        return 1;
    }
    return 0;
}

int array_max(char* arr, int max_len){
    /*Validate that the given array is not bigger than the max number*/
    int size = sizeof(arr)/sizeof(arr[0]);
    if( size > max_len) {
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