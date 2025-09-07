def sort(data: list) -> None:
    for i in range(len(data)):
        for j in reversed(range(i + 1, len(data))):
            if data[j - 1] > data[j]:
                data[j - 1], data[j] = data[j], data[j - 1]
