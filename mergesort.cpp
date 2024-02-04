#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    int i = left, j = mid + 1;
    vector<int> result;

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
}

void mergesort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergesort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
