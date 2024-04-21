from sortFunctions import *
s = [2, 1, 5, 4, 3, 6]
# bubbleSort(s)
# selectionSort(s)
# insertionSort(s)
# countingSort(s)
# s = mergeSort(s)
quickSort(s, 0, len(s) - 1)
print(*s)
