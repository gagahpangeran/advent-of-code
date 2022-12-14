from sys import stdin

lines = []

min_n = min_m = 1e9
max_n = max_m = -1

for s in stdin:
    ln = []
    for pt in s.strip().split(" -> "):
        x, y = map(int, pt.split(","))
        min_n = min(min_n, y)
        max_n = max(max_n, y)
        min_m = min(min_m, x)
        max_m = max(max_m, x)
        ln.append([y, x])
    lines.append(ln)


min_m -= 150
max_m += 150

m = max_m - min_m + 1
n = max_n + 3

grid = [["." for _ in range(m)] for _ in range(n)]


def pg():
    print("\n".join(["".join(g) for g in grid]))


for line in lines:
    for u in range(1, len(line)):
        ci, cj = line[u]
        pi, pj = line[u - 1]

        if ci == pi:
            for v in range(min(cj, pj), max(cj, pj) + 1):
                grid[ci][v - min_m] = "#"
        elif cj == pj:
            for v in range(min(ci, pi), max(ci, pi) + 1):
                grid[v][cj - min_m] = "#"

for u in range(m):
    grid[-1][u] = "#"

mid = 500 - min_m
i = 0
j = mid

while True:
    if grid[i][j] != ".":
        break
    elif i + 1 >= n:
        break
    elif grid[i + 1][j] == ".":
        i += 1
    else:
        if j - 1 < 0:
            break
        elif grid[i + 1][j - 1] == ".":
            i += 1
            j -= 1
        elif j + 1 >= m:
            break
        elif grid[i + 1][j + 1] == ".":
            i += 1
            j += 1
        else:
            grid[i][j] = "o"
            i = 0
            j = mid


res = 0
for i in grid:
    for j in i:
        if j == "o":
            res += 1

assert (grid[0][mid] == "o")
print(res)
