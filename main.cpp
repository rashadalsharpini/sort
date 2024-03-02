#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& data);
void bubbleSort(vector<int>& data);
void swap(int* x, int* y);
int partition(vector<int>& arr, int low, int high);
void quickSort(vector<int>& arr, int low, int high);
void merge(vector<int>& arr, int left, int middle, int right);
void mergeSort(vector<int>& arr, int left, int right);
void insertionSort(vector<int>& data,int size);
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
//    quickSort(data, 0, size - 1);
//    mergeSort(data,0,size-1);
//    insertionSort(data, data.size());
    cout << "Sorted Data: ";
    for (int item : data) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}


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
void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
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
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Recursively sort the two subarrays
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted subarrays
        merge(arr, left, middle, right);
    }
}
void insertionSort(vector<int>& data, int size) {
    // Start from the second element (index 1)
    for (int i = 1; i < size; i++) {
        int key = data[i];
        int j = i - 1;

        // Shift elements of data[0..i-1], that are greater than key, to one position ahead
        // of their current position
        while (j >= 0 && data[j] > key) {
            swap(data[j + 1], data[j]);  // Swap elements using the existing swap function
            j--;
        }
    }
}
