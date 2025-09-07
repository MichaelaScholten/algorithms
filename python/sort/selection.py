''' Sort the list with selection sort. '''
def sort(data: list) -> None:
    # Iterate through the list `len(data)` times.
    for i in range(len(data)):
        # Use the current index (iteration count) as the initial lowest index
        lowest_index = i

        # Find the actual lowest index
        for j in range(i + 1, len(data)):
            if data[lowest_index] > data[j]:
                lowest_index = j

        # Swap the value at the current index with the value at the lowest index.
        data[i], data[lowest_index] = data[lowest_index], data[i]
