def sort(data: list) -> None:
    for i in range(1, len(data)):
        for j in reversed(range(i)):
            if data[j] > data[j + 1]:
                data[j], data[j + 1] = data[j + 1], data[j]
            else:
                break
