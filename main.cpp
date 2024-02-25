#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int>& data) {
    for (int i = 0; i < data.size() - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < data.size(); ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(data[i], data[minIndex]);
        }
    }
}
void bubbleSort(vector<int>& data) {
    for (int i = 0; i < data.size() - 1; ++i) {
        for (int j = 0; j < data.size() - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j=low; j<=high-1; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i+1;
}


void quickSort(vector<int>& arr, int low, int high) {
    int j;
    if(low<high){
        j=partition(arr,low,high);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
}

int main() {
    cout << "enter the size : ";
    int size;cin >> size;
    vector<int> data(size);
    for(auto&i:data)
        cin >> i;
    cout << "Unsorted Data: ";
    for (int item : data) {
        cout << item << " ";
    }
    cout << endl;
//    selectionSort(data);
//    bubbleSort(data);
    quickSort(data, 0, size - 1);
    cout << "Sorted Data: ";
    for (int item : data) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[] if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Recursively sort the two subarrays
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}
