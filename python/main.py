import data
from sort import bubble, insertion, merge, selection
from search import linear, binary
import time

''' Generates and tries to sort data. '''
def attempt_sort(algorithm, length: int) -> None:
    # Start measuring performance
    start = time.perf_counter()

    # Generate the data
    numbers = data.generate_unsorted(length)

    # sort the data
    algorithm(numbers)

    # Check whether it's sorted
    if data.is_sorted(numbers):
        print("Data is sorted")
    else:
        print(numbers[:10])

    # Display performance in seconds
    print(time.perf_counter() - start)

''' Generates data and tries to sort every value in it. '''
def attempt_search(algorithm, length: int) -> None:
    # Start measuring performance
    start = time.perf_counter()

    # Generate the data
    numbers = data.generate_sorted(length)

    # Sort every value in the data
    for i in range(length):
        # search for a value
        index = linear.search(numbers, i)

        # None means the value wasn't found, which isn't possible.
        # So we display a message and break out of the loop
        if index == None:
            print("Failed to find value")
            break

        # Every value is unique, so it should only be found at the current index.
        # Display an error message and break out of the loop for other indices.
        if index != i:
            print("Found value at wrong index")
            break
    else:
        # Search for a value that is not in the list.
        # Display an error message if found.
        # Display a success message if not.
        if linear.search(numbers, length) == None:
            print("Found all values")
        else:
            print("Found non-existent value")

    # Display performance
    print(time.perf_counter() - start)

# Try every sorting algorithm
attempt_sort(bubble.sort, 4_000)
attempt_sort(insertion.sort, 4_000)
attempt_sort(selection.sort, 4_000)
attempt_sort(merge.sort, 100_000)

# Try every search algorithm
attempt_search(linear.search, 8_000)
attempt_search(binary.search, 8_000)
