''' Returns the index of the value or `None`. '''
def search(data: list, value) -> int:
    for i in range(len(data)):
        if data[i] == value:
            return i
    return None
