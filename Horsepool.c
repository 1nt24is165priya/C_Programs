#include<stdio.h>
#include<sys/time.h>
#include<string.h>
#define MAX 256


void buildshiftTable(char pattern[],int m, int shift[] ){
    for(int i = 0;i<MAX;i++){
        shift[MAX] = m;
    }

    for(int j = 0; j<m-1;j++){
        shift[(unsigned char)pattern[j]] = m -1-j;
    }
}


int horsepool(char text[], char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    int shift[MAX];
    
    buildshiftTable(pattern,m,shift);

    int i = m-1;
    while(i<n){
        int k = 0;
        while(k<m && pattern[m-1-k] == text[i-k]){
            k++;

        }
        if(k==m){
            return i-m+1;
        }
        i = i + shift[(unsigned char)text[i]];
    }
    return -1;
}


int main(){
    struct timeval start,end;
    char text[]= "THIS IS A SIMPLE EXAMPLE";
    char pattern[] = "EXAMPLE";

    gettimeofday(&start, NULL);
    int pos = horsepool(text,pattern);
    gettimeofday(&end, NULL);
    printf("Pattern found at the index %d \n", pos );

    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

    printf("Execution time is : %lf\n", time_taken);
    return 0;


}