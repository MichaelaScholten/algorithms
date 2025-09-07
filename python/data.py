''' Generates a reverse sorted list with `length' elements. '''
def generate_unsorted(length: int) -> list[int]:
    return list(reversed(range(length)))

''' Generates a sorted list with `length' elements. '''
def generate_sorted(length: int) -> list[int]:
    return list(range(length))

''' Check whether the list is sorted. '''
def is_sorted(data: list) -> bool:
    for i in range(1, len(data)):
        if data[i - 1] > data[i]:
            return False
    return True
