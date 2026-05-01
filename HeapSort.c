#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
// #include<resource.h>

void swap(int arr[],int i,int j){
    int temp = arr[i];
     arr[i] = arr[j];
     arr[j] = temp;
}

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right < n && arr[right]>arr[largest]){
        largest = right;

    }

    if(largest != i){
        swap(arr,i,largest);
        heapify(arr,n,largest);
    }
}



void heapsort(int arr[],int n){
    for(int i = n/2 -1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i = n-1; i >= 0; i--){
        swap(arr,0,i);
        heapify(arr,i,0);
    }
}

int main(){
    struct timeval start, end;
    // struct rusage usage;
    int arr[] = {12,4,16,2,8,19};
    int n = 6;
    for(int i = 0;i<n ; i++){
        printf("%d\t",arr[i]);
        //printf("\t");
        
    }
    gettimeofday(&start,NULL);
    heapsort(arr,n);
    gettimeofday(&end,NULL);
    //getrusage(RUSAGE_SELF,&usage);

    printf("\nSORTED ARRAY IS : ");

    for(int i = 0; i<n; i++){
        printf("%d\t",arr[i]);
    }

    double time_taken;
    float memory_used;
    time_taken =(end.tv_sec-start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;
    printf("\nExecution time = %lf\n ",time_taken);
   // printf("Memory used = %ld KB\n",usage.ru_maxrss);
    return 0;
}

