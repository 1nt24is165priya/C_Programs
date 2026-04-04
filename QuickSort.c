#include<stdio.h>
#include<sys/time.h>


void swap(int arr[],int i,int j){
   int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr, i, j);
        }
    }
        swap(arr, i+1 , high);
        return i+1;
    }


void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int arr[100];
    int i,n;
    struct timeval start,end;
    //struct rusage usage;
    printf("enter the value of n:\n");
    scanf("%d", &n);
    printf("enter the %d elements: \n", n);
    for(i = 0; i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("\n");
    gettimeofday(&start, NULL);
    quickSort(arr,0,n-1);
    gettimeofday(&end, NULL);

    printf("Sorted array is:\n");
    for(int i =0 ; i<n; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n")

    double time_taken;
    time_taken = (end.tv_sec-start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;
    printf(" Execution Time is : %lf \n", time_taken);
    return 0;

}