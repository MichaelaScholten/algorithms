''' Returns the index of the value or `None`. '''
def search(data: list, value) -> int:
    a, b = 0, len(data)
    while b - a > 1:
        c = (a + b) // 2
        if data[c] == value:
            return c
        elif data[c] < value:
            a = c
        else:
            b = c

    return a if data[a] == value else None
