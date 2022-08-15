#include <stdio.h>
#include <string.h>
#define   N 3 

int resize(int in_arr[N][N], int out_arr[N*2][N*2]){
    /* Gets 2 arrays (input and output) and fills the output array as 2x2 square of identical numbers according to the input array*/
    int x=0, y=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            out_arr[i+y][j+x] = in_arr[i][j];
            out_arr[i+1+y][j+x] = in_arr[i][j];
            out_arr[i+y][j+x+1] = in_arr[i][j];
            out_arr[i+1+y][j+x+1] = in_arr[i][j];
            x++;
        }
        y++;
        x=0;
        }

    return 0;
    }

int matDiagonalPrint(int arr[N][N]){
    /*Gets a matrix and prints it diagonally from the top left */
    int c = 0;
    for(int i=0; i < (N*2-1); i++){

        if(i < N){
            c = i;
            for(int j=0; j <= i; j++){
                printf("%d ",arr[c][j]);
                c--;
            }
        }
        else{
           c = i-N+1;
           for(int j=N-1;c < N;j--){
               printf("%d ",arr[j][c]);
               c++;
           }
        }
        printf("\n");
    }
    return 0;
}

/*Only for tests*/
int main(){
    
    int in_arr[N][N] = {{1,2,3},
                      {4,5,6},
                      {7,8,9}};

    int out_arr[N*2][N*2] = {{0,0,0,0,0,0},
                      {0,0,0,0,0,0},
                      {0,0,0,0,0,0},
                      {0,0,0,0,0,0},
                      {0,0,0,0,0,0},
                      {0,0,0,0,0,0}};

        resize(in_arr,out_arr);

      int arr[N][N] = {{1,2,3},
                      {4,5,6},
                      {7,8,9},};
        matDiagonalPrint(arr);
         return 0;
}