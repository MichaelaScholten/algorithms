def generate_unsorted(length: int) -> list[int]:
    return list(reversed(range(length)))

def generate_sorted(length: int) -> list[int]:
    return list(range(length))

def is_sorted(data: list) -> bool:
    for i in range(1, len(data)):
        if data[i - 1] > data[i]:
            return False
    return True
