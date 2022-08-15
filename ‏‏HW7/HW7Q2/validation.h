#include <stdio.h>

#ifndef VALIDATION_H
#define VALIDATION_H

/*General validation functions*/
int string_Length(char* str, int len, char* fieldName);
int only_digits_string_length(char* str, int len, char* fieldName);
int min_number(int num, int min_num, char* fieldName);
int max_number(int num, int max_num, char* fieldName);
int max_digits(int num, int max_digits, char* fieldName);
int exact_digits(int num, int max_digits, char* fieldName);
int array_max(char* arr, int max_len);
int not_empty_arr(char* arr);

#endif