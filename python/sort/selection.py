def sort(data: list) -> None:
    for i in range(len(data)):
        lowest_index = i
        for j in range(i + 1, len(data)):
            if data[lowest_index] > data[j]:
                lowest_index = j
        data[i], data[lowest_index] = data[lowest_index], data[i]
