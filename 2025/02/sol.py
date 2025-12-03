ranges = [tuple(map(int, rg.split("-"))) for rg in input().strip().split(",")]

mx = str(max([r for _, r in ranges]))
half = (len(mx) + 1) // 2
mx_half = mx[:half]

invalid1 = set()
invalid2 = set()

for i in range(1, int(mx_half)+1):
    for j in range(2, len(mx)+1):
        now = int(str(i) * j)

        if now > int(mx):
            break

        if j == 2:
            invalid1.add(now)

        invalid2.add(now)

res1 = 0
res2 = 0

for l, r in ranges:
    for inv in invalid1:
        if l <= inv <= r:
            res1 += inv

    for inv in invalid2:
        if l <= inv <= r:
            res2 += inv


print(res1)
print(res2)
