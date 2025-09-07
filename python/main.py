from sort import data, bubble, insertion, merge, selection
import time

def attempt_sort(algorithm, length: int):
    start = time.perf_counter()
    numbers = data.generate(length)
    algorithm(numbers)
    if data.is_sorted(numbers):
        print("Data is sorted")
    else:
        print(numbers[:10])
    print(time.perf_counter() - start)

attempt_sort(bubble.sort, 4_000)
attempt_sort(insertion.sort, 4_000)
attempt_sort(selection.sort, 4_000)
attempt_sort(merge.sort, 100_000)
