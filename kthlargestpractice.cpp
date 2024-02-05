#include<bits/stdc++.h>
using namespace std;
int find_rank(vector<int>& arr, int low, int high, int rank);

int goodPartition(vector<int>&arr, int low, int high)
{
  int m =(high-low+1)/5;
  int i = low;
  int j = low;
  if(m>1)
  {
    while(i+4<= high)
      {
        sort(arr.begin()+i,arr.begin()+i+4);
        swap(arr[j],arr[i+2]);
        j++;
        i+=5;
      }

  }
  return find_rank(arr,low,low+m-1,m/2);

}
int partition(vector<int>& arr, int low, int high) {
    int pivot = rand() % (high - low + 1) + low;
    swap(arr[pivot], arr[high]);
    pivot = high;
    int i = low - 1;
    int j = low;
    while (j < high) {
        if (arr[j] < arr[pivot]) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
int find_rank(vector<int>& arr, int low, int high, int rank) {
    if (low < high) {
        int k = goodPartition(arr, low, high);

        if (rank == high-k+1) {
            return arr[k];
        } else if (rank < high-k+1) {
            return find_rank(arr, k + 1, high, rank);
        } else {
            return find_rank(arr, low, k - 1, rank - (high-k+1));
        }
    } else if (low == high) {
        if (rank == 1) {
            return arr[low];
        }
    }
    return -1;
}
int main() {
    // Test Cases
    vector<int> arr1 = {5};
    vector<int> arr2 = {3, 2, 5, 1};
    vector<int> arr3 = {1, 2, 3, 4, 5};
    vector<int> arr4 = {5, 4, 3, 2, 1};
    vector<int> arr6 = {10,9,8,7,6,5,4,3,2,1};
    vector<int> arr5 = {10, 7, 7, 8, 2, 5, 3, 8, 5, 7, 9, 4, 6, 23, 3, 4, 0, 19, 1, 5};

    // Test Case 1: Array with one element
    cout << "Value at rank 1 in arr1: " << find_rank(arr1, 0, arr1.size() - 1, 1) << endl;

    // Test Case 2: Random array with a few elements
    cout << "Value at rank 2 in arr2: " << find_rank(arr2, 0, arr2.size() - 1, 2) << endl;

    // Test Case 3: Sorted array
    cout << "Value at rank 3 in arr3: " << find_rank(arr3, 0, arr3.size() - 1, 3) << endl;

    // Test Case 4: Reverse sorted array
    cout << "Value at rank 2 in arr4: " << find_rank(arr4, 0, arr4.size() - 1, 2) << endl;

    // Test Case 5: Random array with duplicate elements
    cout << "Value at rank 7 in arr5: " << find_rank(arr5, 0, arr5.size() - 1, 7) << endl;

    cout<<"Value at 3rd rank in arr6: "<<find_rank(arr6,0,arr6.size()-1,3)<<endl;

    return 0;
}

