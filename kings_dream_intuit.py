def solve(N, m):
    S = list(range(1, m + 1))
    return S * (N // m) + [S:N % m]