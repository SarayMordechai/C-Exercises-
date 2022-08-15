#include <stdio.h>
#include <math.h>

int main(void){
    /*Prints all the pythogorean Triplets in the range of 100*/
    int k,j,i;
    printf("The Pythogorean Triplets in the range of 100 are: \n ");
    for(k=1;k<100;k++){
        for(j=k;j<100;j++){
            for(i=j;i<100;i++){
                if(i*i==k*k+j*j){
                    printf("%d , %d , %d\n",k,j,i);
                }
            }
        }
    }
    return 0;
}