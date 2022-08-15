#include <stdio.h>
#include <math.h>

int numOccurs(long number , int digit){
    /*Gets a number and a digit and returns the number of times the digit appears in the number*/
    int count = 0, div = 0;
    while(number != 0){
         div = number %10 ;
         number = number / 10;
         if (div == digit){
            count+= 1;
         }
    }
    return count;
}

int maxOccurs(long number){
    /*Gets a number and returns the digit that appears most times in it*/
    int div = 0, numOcc = 0, maxOcc = 0, maxNum = 0;
    long newNum = number;
    while ((newNum != 0))
    {
       div = newNum %10 ;
       newNum = newNum / 10;
       numOcc = numOccurs(number , div);
       if (numOcc > maxOcc){
           maxOcc = numOcc;
           maxNum = div;
       }
       else if (numOcc == maxOcc){
        
       /*If there are several digits that appears the same amount of times save the bigger one*/
           if(div > maxNum){
               maxNum = div;
           }
       }   
    }
    return maxNum;
}

int long delReverse (long number, int digit){
    /*Gets a number and a digit and returns the reversed number without the digits*/
    int div = 0, revNum = 0;
     while (number != 0)
    {
        div = number % 10 ;
        number = number / 10 ;
            if(div != digit){
                 revNum = revNum*10;
                 revNum+=div;
         }
    }
    return revNum;
}

void printDigits(long number){
    /*Gets a number and prints the digits according to how many times they appear in the number(from high to low)*/
    int maxNum = 0;
    printf("The digits are : ");
    while (number != 0){
        maxNum=maxOccurs(number);
        printf("%d ", maxNum);
        number = delReverse(number , maxNum);
    } 
}

int main(){
    /*Gets a number from the user and prints the digits*/
    long x;
    printf("Enter a positive number: ");
    scanf("%ld",&x);
    printDigits(x);
    return 0;
}