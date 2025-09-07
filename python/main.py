import data
from sort import bubble, insertion, merge, selection
from search import linear, binary
import time

def attempt_sort(algorithm, length: int) -> None:
    start = time.perf_counter()
    numbers = data.generate_unsorted(length)
    algorithm(numbers)
    if data.is_sorted(numbers):
        print("Data is sorted")
    else:
        print(numbers[:10])
    print(time.perf_counter() - start)

def attempt_search(algorithm, length: int) -> None:
    start = time.perf_counter()
    numbers = data.generate_sorted(length)
    for i in range(length):
        index = linear.search(numbers, i)
        if index == None:
            print("Failed to find value")
            break
        if index != i:
            print("Found value at wrong index")
            break
    else:
        if linear.search(numbers, length) == None:
            print("Found all values")
        else:
            print("Found non-existent value")
    print(time.perf_counter() - start)

attempt_sort(bubble.sort, 4_000)
attempt_sort(insertion.sort, 4_000)
attempt_sort(selection.sort, 4_000)
attempt_sort(merge.sort, 100_000)

attempt_search(linear.search, 8_000)
attempt_search(binary.search, 8_000)
