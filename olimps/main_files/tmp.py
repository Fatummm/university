

def Solve() -> None:
    n, m = [int(x) for x in input().split()]
    shift = 0
    for i in range(n):
        minute, side = [int(x) for x in input().split()]
        if (minute + shift) % 2 != side % 2:
            shift += 1
    print(m - shift)


t = int(input())
while (t):
    t -= 1
    Solve()
