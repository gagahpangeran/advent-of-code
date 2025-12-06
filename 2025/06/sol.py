from sys import stdin
from math import prod

arr = []
grid = []

for s in stdin:
    arr.append(s.strip().split())
    grid.append(list(s.replace("\n", " ")))

ops = arr[-1]
all_nums = [list(map(int, a)) for a in arr[:-1]]
all_nums = [list(r) for r in zip(*all_nums)]

res1 = 0

for i in range(len(ops)):
    num = all_nums[i]
    res1 += (sum if ops[i] == "+" else prod)(num)

print(res1)

grid = [list(r) for r in zip(*grid)]

cur_ops = "x"
nums = []

res2 = 0
for g in grid:
    if all(c == " " for c in g):
        assert cur_ops != "x"
        assert len(nums) > 0

        res2 += (sum if cur_ops == "+" else prod)(nums)

        nums = []
        cur_ops = "x"
        continue

    if g[-1] in ["+", "*"]:
        cur_ops = g[-1]

    num = int("".join(g[:-1]))
    nums.append(num)

print(res2)
