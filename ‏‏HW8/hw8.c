#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

void write_reverse(char* str, FILE* file){
    int len = strlen(str) - 1, i = 0;
    /*print the words from the last to one before the first */
    for(i = len; i > 0; i--){
        if(isspace(str[i])){
            fprintf(file, "%s", str+i+1);
            str[i] = '\0';
        }
    }
    /*Print the first word at last place*/
    fprintf(file, "%s", str);
}

char* replace(int argc, char** argv){
    int i = 0;
    char buffer[1000];
    char* fname = argv[1];
    char* outName = malloc(strlen(fname) + 5);
    FILE* src  = fopen(fname, "r");
    FILE* dest_file;
    /*Check if the file exists*/
    if (src == NULL){
        printf("Open Failed");
        exit(1);
    }
    strcpy(outName, fname);
    strcat(outName, ".rpl");
    dest_file = fopen(outName, "w");

    while(!feof(src)){
        char c = fgetc(src);
        if(c != '\n'){
            buffer[i] = c;
        }
        i++;
        if(c == '.'){
            buffer[i] = '\0';
            i = 0;
            write_reverse(buffer, dest_file);
        }
    }
    fclose(src);
    fclose(dest_file);
    return outName;
}

void encrypt(char* fname){
    char* newName = malloc(strlen(fname) + 6);
    int i = 0, len = 0;
    char ch;
    FILE* dst;
    FILE* src = fopen(fname, "r");
    if(src == NULL){
        printf("Open Failed");
        exit(1);
    }

    len = ftell(src)-2;
    
    strcpy(newName, fname);
    strcat(newName, ".bend");
    dst = fopen(newName, "w");

    for(i = 0; i < len/2 ; i++){
        fseek(src, i, SEEK_SET); /*Get from the start of the file */
        ch = fgetc(src);
        fputc(ch, dst); /*write char into file*/

        fseek(src, -i, SEEK_END); /*Get from the end of the file */
        ch = fgetc(src);
        fputc(ch, dst); /*write char into file*/
    }
}

int main(){

    return 0;
}
