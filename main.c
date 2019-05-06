#include <stdio.h>
#include <stdlib.h>
#define max 1000
void swap(int *a,int i,int j);
void max_heapify(int arr[],int parentindex,int heapsize);
void prepare_sort(int arr[],int length);


int i,j;
static int total;

int main()
{
    int arr[max];
     srand(time(NULL));
  for(i=0;i<max;i++){

     arr[i]=rand()%10000;
  }
   printf("array you enter is\n");
  /* for(i=0;i<max;i++){
    printf("%d  ",arr[i]);

   }*/
      printf("\n array after sorted is\n");
prepare_sort(arr,max);
   for(i=0;i<max;i++){
    printf("%d  ",arr[i]);

   }
    return 0;
}
void max_heapify(int arr[],int parentindex,int heapsize){

int leftindex=2*parentindex+1;
int rightindex=2*parentindex+2;
int newindex=parentindex;
if(leftindex<=heapsize&&arr[leftindex]>arr[parentindex]){

    newindex=leftindex;
}
else{
  newindex=parentindex;
}
if(rightindex<=heapsize&&arr[rightindex]>arr[newindex]){

    newindex=rightindex;
}
if(newindex!=parentindex){
    swap(arr,parentindex,newindex);
    max_heapify(arr,newindex,heapsize);
}

}
void swap(int *a,int i,int j){
int temp=a[i];
a[i]=a[j];
a[j]=temp;

}
void prepare_sort(int arr[],int length){
int total=length-1;
for(i=total/2;i>=0;i--){

    max_heapify(arr,i,total);
}
for(i=total;i>=0;i--){
    swap(arr,0,i);
    total--;
    max_heapify(arr,0,total);
}

}



