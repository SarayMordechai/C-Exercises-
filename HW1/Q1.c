#include <stdio.h>
#include <math.h>

int factorial(int num){
    /*Gets a number and returns the factorial calculation*/
    int i, res = 1;
    for(i=2 ;i<=num ; i++){
        res*=i;
    }
    return res;
} 

void sin_taylor(float angle){
    /*Gets an angle and prints the sin value(By taylor calc)*/
    float q, sum =0;
    int i,j,limit=10;
    q = angle;
    angle = angle*(3.1415/180);
    
    for(i=1,j=1;i<=limit;i++,j=j+2) {

        /*Odd numbers*/
        if(i%2!=0) {
            sum=sum+pow(angle,j)/factorial(j);
            }

        /*Even numbers*/
        else{
            sum=sum-pow(angle,j)/factorial(j);
            }
        }
    printf("Sin(%0.1f): %f",q,sum);
}

int main (void){
    /*Gets an angle from the user and send it to the function for calculation*/
    float x;
    printf("Enter the value of x of sinx series: ");
    scanf("%f",&x);
    sin_taylor(x);
    return 0;
}