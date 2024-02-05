#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr, int l, int r);
void quicksort(vector<int>&arr, int l, int r);

int partition(vector<int>& arr, int low, int high) {
    int pivot = rand() % (high - low + 1) + low;
    swap(arr[pivot], arr[high]);
    pivot = high;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < arr[pivot]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<int>&arr, int l, int r)
{
  if(l<r)
  {
    int pivot = partition(arr,l,r);
    quicksort(arr,l,pivot-1);
    quicksort(arr,pivot+1,r);
  }
}
int main() {
    vector<int> arr = {10, 7, 7, 8, 2, 5, 3, 8, 5, 7, 9, 4, 6, 23, 3, 4, 0, 19, 1, 5};
    quicksort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
