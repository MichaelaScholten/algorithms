''' Sort items with insertion sort. '''
def sort(data: list) -> None:
    # Iterate through the list `len(data) - 1` times
    for i in range(1, len(data)):
        # Iterate from elemt `i` to 0
        for j in reversed(range(i)):
            # Swap elements if in the wrong order, stop if in order
            if data[j] > data[j + 1]:
                data[j], data[j + 1] = data[j + 1], data[j]
            else:
                break
