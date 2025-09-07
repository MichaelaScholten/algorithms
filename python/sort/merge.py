''' Sort list using merge sort. '''
def sort(data: list) -> None:
    # Take the length of the list.
    length = len(data)

    # If the list is 2 elements long and the elements are unsorted, swap them.
    # If the list is longer than 2 elements, sort the list.
    if length == 2 and data[0] > data[1]:
        data[0], data[1] = data[1], data[0]
    elif length > 2:
        # Take a shallow copy of both lists
        a, b = data[:length // 2].copy(), data[length // 2:].copy()
        
        # Sort both copies
        sort(a)
        sort(b)

        # Clear the original list
        data.clear()

        # Add elements from both copies to the original list
        while len(a) > 0 and len(b) > 0:
            if a[0] < b[0]:
                data.append(a.pop(0))
            else:
                data.append(b.pop(0))

        # Add the elements that are not yet added to the list.
        data.extend(a)
        data.extend(b)
