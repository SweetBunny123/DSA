import random

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def randomised_partition(arr, low, high):
    pivot = random.randint(low, high)
    arr[pivot], arr[high] = arr[high], arr[pivot]
    return partition(arr, low, high)

def quicksort(arr, low, high):
    if low < high:
        pivot = randomised_partition(arr, low, high)
        quicksort(arr, low, pivot - 1)
        quicksort(arr, pivot + 1, high)

if __name__ == "__main__":
    arr = [10, 7, 7, 8, 2, 5, 3, 8, 5, 7, 9, 4, 6, 23, 3, 4, 0, 19, 1, 5]
    quicksort(arr, 0, len(arr) - 1)
    for num in arr:
        print(num, end=" ")
