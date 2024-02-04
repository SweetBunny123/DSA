#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int left, int mid, int right, int a, int b) {
    int i = left, j = mid + 1;
    vector<int> result;
    int count = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]*a+b) {
            count += right-j+1;
            i++;
        } else {
            j++;
        }
    }
    i = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            result.push_back(arr[i]);
            i++;
        } else {
            result.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        result.push_back(arr[i]);
        i++;
    }

    while (j <= right) {
        result.push_back(arr[j]);
        j++;
    }

    for (int i = left; i <= right; i++) {
        arr[i] = result[i - left];
    }
  return count;
}

int  mergesort(vector<int> &arr, int left, int right, int a, int b) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count+= mergesort(arr, left, mid,a,b);
        count+= mergesort(arr, mid + 1, right, a, b);
        count+= merge(arr, left, mid, right, a, b);
    }
  return count;

  
}

int main() {
    vector<int> arr = {4,3,2,1};
    int arr_size = arr.size();

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int inversion = mergesort(arr, 0, arr_size - 1, 1, 0);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout<<"The total inversion is"<<inversion<<endl;

    return 0;
}
