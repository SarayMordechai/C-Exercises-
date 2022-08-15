#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

char encrypt(char input , unsigned int k){
    /*Gets an allcaps letter and a key and returns an encrypted letter k steps ahead according to the given key*/
    int x = 0;
    if isupper(input){
       x = (tolower(input) - 'a' + k + 26) %26;
       input = 'a' + x;
    }
    return input;
}

char decrypt(char input , int k){
    /*Gets a letter and a key and returns the decrypted letter acorrding to the given key*/
    int x = 0;
    if islower(input){
       x = (input - 'a' - k + 26)%26;
       input = 'a' + x; 
       input = toupper(input);
    }
    return input;
}

int main (void){
    /*Gets from the user a key and a text in all caps and encrypt it*/
    char a[100] ;
    int length, i = 0, k = 0;
    printf("Enter allcaps letters: \t");
    gets(a);
    printf("Enter a key: \t");
    scanf("%d" ,&k);

    /*Check that the number is positive*/
    if (k < 0){
        printf("The number must be positive");
        return 1;
    }
    length = strlen(a);
    for(i=0 ; i < length ; i++){

        /*Check that the letter is an allcap*/
        if(isupper(a[i])){
            a[i] = encrypt(a[i],k);
        }
        else{
            printf("The string needs to contain only allcaps letters");
            return 1;
        }
    }
    printf("%s" ,a);
    return 0;
}