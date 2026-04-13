
def solve():
    a, b, c, d = [int(x) for x in input().split()]
    if (b / 2  - 1 > a) or (a / 2 - 1 > b):
        print("NO")
        return None
    c -= a
    d -= b
    if c < 0 or d < 0 or (d / 2 - 1 > c) or (c / 2 - 1 > d):
        print("NO")
        return None
    print("YES")


t = int(input())
while t:
    solve()
    t -= 1
