#include<stdio.h>
#include<sys/time.h>
int main(){
    int a[100],i,j,min,temp,n;
    struct timeval start,end;
    printf("Enter the number of elments\n");
    scanf("%d",&n);
    printf("enter the array elements:\n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    gettimeofday(&start, NULL);

    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        } 
    }
    gettimeofday(&end,NULL);
    double time_taken;
    time_taken = (end.tv_sec-start.tv_sec)*1000000.0;
    time_taken = (time_taken+(end.tv_usec-start.tv_usec))/1000000.0;

    printf("Sorted elements are:\n");
    for(i=0;i<n;i++){
        printf("%d\n", a[i]);
    }

    printf("Execution time = %f seconds",time_taken);
    return 0;
}