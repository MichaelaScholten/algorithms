def sort(data: list):
    length = len(data)
    if length == 2 and data[0] > data[1]:
        data[0], data[1] = data[1], data[0]
    elif length > 2:
        a, b = data[:length // 2].copy(), data[length // 2:].copy()
        sort(a)
        sort(b)
        data.clear()
        while len(a) > 0 and len(b) > 0:
            if a[0] < b[0]:
                data.append(a.pop(0))
            else:
                data.append(b.pop(0))
        data.extend(a)
        data.extend(b)
