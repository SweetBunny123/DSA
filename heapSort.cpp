#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr, int n, int i)
{   int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if(l < n && arr[l] > arr[largest])
        largest = l;
    
    if(r < n && arr[r] > arr[largest])
        largest = r;
    
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int>& arr)
{   int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void heapSort(vector<int>&arr)
{   int n = arr.size();
    buildMaxHeap(arr);    
    for(int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{   vector<int> nonHeapedArray = {3, 8, 7, 6, 3, 9, 3, 2, 12};
    heapSort(nonHeapedArray);
    for(int i = 0; i < nonHeapedArray.size(); i++)
      {
        cout<<nonHeapedArray[i]<<" ";
      }
    cout<<endl;
  return 0;
}