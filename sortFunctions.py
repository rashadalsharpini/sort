# int partition(vector<int>& arr, int low, int high);
# void quickSort(vector<int>& arr, int low, int high);
# void merge(vector<int>& arr, int left, int middle, int right);
# void mergeSort(vector<int>& arr, int left, int right);
def bubbleSort(data):
    for i in data:
        for j in range(len(data) - i - 1):
            if data[j] > data[j + 1]:
                data[j + 1], data[j] = data[j], data[j + 1]


def selectionSort(data):
    for i in range(len(data) - 1):
        minIndex = i
        for j in range(i + 1, len(data)):
            if data[j] < data[minIndex]:
                minIndex = j
        if minIndex != i:
            data[i], data[minIndex] = data[minIndex], data[i]


def insertionSort(data):
    for i in range(1, len(data)):
        j = i
        while j > 0 and data[j - 1] > data[j]:
            data[j - 1], data[j] = data[j], data[j - 1]
            j -= 1


def countingSort(data):
    frq = [0]*100
    for i in data:
        frq[i] += 1
    data.clear()
    for i in range(100):
        if frq[i] != 0:
            while frq[i] > 0:
                data.append(i)
                frq[i] -= 1


def mergeSort(data):
    if len(data) <= 1:
        return data

    mid = len(data) // 2
    left = data[:mid]
    right = data[mid:]

    leftSorted = mergeSort(left)
    rightSorted = mergeSort(right)
    return merge(leftSorted, rightSorted)


def merge(left, right):
    merged = []
    i = 0

    j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1

    merged += left[i:]
    merged += right[j:]
    return merged


def quickSort(arr, low, high):
    if low < high:
        j = partition(arr, low, high)
        quickSort(arr, low, j - 1)
        quickSort(arr, j + 1, high)


def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        guess = arr[mid]

        if guess == target:
            return mid
        if guess > target:
            high = mid - 1
        else:
            low = mid + 1

    return -1
