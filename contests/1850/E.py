def sqrt(n: int):
    low = 0
    high = n
    while low <= high:
        middle = (low + high) // 2
        square = middle * middle
        if square == n:
            return middle
        elif square < n:
            low = middle + 1
        else:
            high = middle - 1

    return 0


def solve():
    n, c = list(map(int, input().split()))
    s = list(map(int, input().split()))

    A = 4 * n
    B = 4 * sum(s)
    C = sum(map(lambda x: x * x, s)) - c
    delta = B * B - 4 * A * C

    result = (-B + sqrt(delta)) // (2 * A)
    print(result)


if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        solve()
