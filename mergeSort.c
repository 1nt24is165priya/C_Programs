#include<sys/resource.h>
#include<sys/time.h>
#include<stdio.h>

void merge(int A[],int st,int mid,int end){
    int temp[100];
    int i = st;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= end){
        if( A[i]<=A[j]){
            temp[k]=A[i];
            i++;
        }
        else{
            temp[k]=A[j];
            j++;
        }
        k++;
    }
    
    while(i <= mid){
        temp[k]=A[i];
        i++;
        k++;
    }

    while(j <= end){
        temp[k]=A[j];
        j++;
        k++;
    }
    for(int idx = 0;idx < k; idx++){
        A[idx+st]=temp[idx];
    }
}    

void mergeSort(int A[],int st,int end){
    if(st<end){
        int mid = (st+end)/2;
        mergeSort(A,st,mid);
        mergeSort(A,mid+1,end);
        merge(A,st,mid,end);
        }
}

int main(){
    int n;
    int A[100];
    struct timeval start,end;
    struct rusage usage;

    printf("enter the value of n:\n");
    scanf("%d",&n);
    printf("enter the %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    gettimeofday(&start,NULL);
    mergeSort(A,0,n-1);
    gettimeofday(&end,NULL);
    getrusage(RUSAGE_SELF,&usage);

    printf("Sorted array:\n");
    for(int i = 0;i<n;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");

    double time_taken;
    time_taken=(end.tv_sec - start.tv_sec)+(end.tv_usec - start.tv_usec)/1000000.0;
    printf("Execution time is %lf seconds\n",time_taken);
    printf("Memory used is %ld KB\n",usage.ru_maxrss);
    return 0;
}
