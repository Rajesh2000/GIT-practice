//Insertion Sort
//Insert an element from unsorted array to its correct position in sorted array.

#include<iostream>
#include<climits>
using namespace std;

int InsertionSort(int arr[],int size){
    
    for(int i=0 ; i<size; i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}



int main(){
   int size;
   
   cin>>size;
   int arr[size];
   
   for(int i=2; i<size; i++){
       cin>>arr[i];
   }
   InsertionSort(arr,size);

    
   for(int i=1; i<size; i++){
       cout<<arr[i]<<" ";
   }
    return 1;

}
