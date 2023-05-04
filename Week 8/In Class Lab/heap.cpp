#include <iostream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
  int left = 2*root + 1;
  int right = 2*root + 2;
  int max = root;

  if(left <= n-1 && arr[left] > arr[max]){
    max = left;
  }
  if(right <= n-1 && arr[right] > arr[max]){
    max = right;
  }
  if(max != root){
    int temp = arr[root];
    arr[root] = arr[max];
    arr[max] = temp;
    heapify(arr, n, max);
  }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   int i = n/2-1;
   for(int i = n/2 - 1; i >= 0; i--){
      heapify(arr, n, i);
   }
   // extracting elements from heap one by one
   for(int j=n-1; j>0; j--){
      int temp = arr[0];
      arr[0] = arr[j];
      arr[j] = temp;
      heapify(arr, j, 0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int n; 
   cout << "Input the array size" << endl;
   cin >> n;
   int arr[n]; 
   cout << "Enter " << n << " integers:" << endl;
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   int heap_arr[] = {4,17,3,12,9,6};
   
   cout<<"Input array"<<endl;
   displayArray(arr,n);
  
   heapSort(arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(arr, n);
}