import typing as tp

def find_value(lst: tp.List[int], target: int) -> bool:
    l = 0
    r = len(lst)
    while (r >= l):
        m = (r + l) // 2
        if lst[m] > target:
            r = m - 1
        elif lst[m] < target:
            l = m + 1
        else:
            return True
    return False

a = [1, 2, 3, 4, 6, 7, 8, 9, 10]

print(f"Array: {a}")

for i in range(10):
    print(f"Target: {i}. Result: {'Found' if find_value(a, i) else 'Not Found'}")

