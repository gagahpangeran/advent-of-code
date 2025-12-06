from sys import stdin

rgs = []

query = False

res1 = 0

for s in stdin:
    s = s.strip()

    if len(s) == 0:
        query = True
        continue

    if query:
        num = int(s)

        for l, r in rgs:
            if l <= num <= r:
                res1 += 1
                break
        continue

    l, r = map(int, s.split("-"))
    rgs.append([l, r])

print(res1)

rgs.sort(key=lambda x: x[0])
new_rgs = [rgs[0]]

for i in range(1, len(rgs)):
    l, r = rgs[i]

    pl, pr = new_rgs[-1]
    if l <= pr:
        new_rgs[-1][1] = max(r, new_rgs[-1][1])
    else:
        new_rgs.append(rgs[i])

res2 = 0
for l, r in new_rgs:
    res2 += r - l + 1

print(res2)
