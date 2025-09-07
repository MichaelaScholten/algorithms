''' Uses bubble sort to sort a list in place. '''
def sort(data: list) -> None:
    # Iterate through the list `len(data)` times.
    for i in range(len(data)):
        # Iterate through the list, starting after the sorted elements.
        for j in reversed(range(i + 1, len(data))):
            # Swap values if in the wrong order
            if data[j - 1] > data[j]:
                data[j - 1], data[j] = data[j], data[j - 1]
