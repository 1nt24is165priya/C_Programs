
#include<stdio.h>
#include<sys/time.h>

int main(){
    int i,j,key;
    int a[100],n;
    struct timeval start,end;

    printf("enter the value of n:\n");
    scanf("%d",&n);
    printf("Enter the %d elements: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    gettimeofday(&start,NULL);
    for(i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    gettimeofday(&end,NULL);

    double time_taken;
    time_taken=(start.tv_sec-end.tv_sec)*1000000.0;
    time_taken=(time_taken+(start.tv_usec-end.tv_usec))/1000000.0;

    printf("final arrray of Insertionsort is:\n");
    for(i=0;i<n;i++){
        printf("%d\t", a[i]);
    }
    printf("\n");

    printf("Execution time = %f seconds\n", time_taken);
    return 0;

}
