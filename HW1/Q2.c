#include <stdio.h>
#include <math.h>

int maxDigit(int num){
    /*Gets a positive number and return the biggest digit*/
    int max = 0 , div = 0;
    while (num > 0)
    {
        div = num %10 ; 
        num = num / 10;
    
        if (div > max){
            max=div;
        }
    }  
    return max;
}

int delMaxnum(int num){
    /*Gets a positive number and delete the biggest digit*/
    int i = 1, newNum = 0, div = 0;
    int maxNum = maxDigit(num); 

    while (num != 0)
    {
     div = num % 10 ;
     num = num / 10 ;
         if(maxNum != div){
             newNum += div*i;
                i*=10;
         }
    }
    return newNum;
}

int main(void){
    /*Gets a positive number from the user and prints the number without the biggest digit*/
    int x;
    printf("Enter a positive number: ");
    scanf("%d",&x);

    /*Check that the number is positive*/
    if(x < 0){
        printf("The number must be positive");
        return 1;
    }
    printf("%d", delMaxnum(x));
    return 0;
}