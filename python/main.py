from sort import data, bubble

def attempt_sort(algorithm):
    numbers = data.generate(1000)
    algorithm(numbers)
    if data.is_sorted(numbers):
        print("Data is sorted")
    else:
        print(numbers[:10])

attempt_sort(bubble.sort)
