# This function determines a partition given a range of (low, high):
def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1

# Recursive function for quicksort:
def quicksort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quicksort(array, low, pi - 1)
        quicksort(array, pi + 1, high)

# Main Code:
arr = [94, 64, 99, 70, 79, 37, 46, 34, 10, 11]
print("\nBefore Sorting:")
print(arr)
quicksort(arr, 0, len(arr)-1)
print("\nAfter Sorting:")
print(arr)
