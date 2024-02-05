#include<bits/stdc++.h>
using namespace std;
int find_rank(vector<int>& arr, int low, int high, int rank);
int partition(vector<int>& arr, int low, int high) {
    int pivot = rand()%(high-low+1)+low;
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
int find_rank(vector<int>& arr, int low, int high, int rank) {
    if (low < high) {
        int k = partition(arr, low, high);
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
    vector<int> arr5 = {121,42,87,7,23,21,19,11,38,35,88,2,12,90,55,78,23,123,5,26,34,65,23,78,43,16};

    // Test Case 5: Random array with duplicate elements
    cout << "Value at rank 7 in arr5: " << find_rank(arr5, 0, arr5.size() - 1, 11) << endl;

    return 0;
}

