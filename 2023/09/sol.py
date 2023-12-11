from sys import stdin

res = 0
res2 = 0

for s in stdin:
    v = list(map(int, s.strip().split()))
    ls = [v]

    while not all(i == 0 for i in ls[-1]):
        cur = ls[-1]
        l = [cur[i]-cur[i-1] for i in range(1, len(cur))]
        ls.append(l)

    ls.reverse()

    for i in range(1, len(ls)):
        val = ls[i - 1][-1] + ls[i][-1]
        ls[i].append(val)

    for i in range(1, len(ls)):
        val = ls[i][0] - ls[i - 1][0]
        ls[i].insert(0, val)

    res += ls[-1][-1]
    res2 += ls[-1][0]

print(res)
print(res2)
