from sys import stdin

res = 0

wat = [0]

for s in stdin:
    _, nums = s.strip().split(": ")
    swin, sown = nums.strip().split(" | ")
    win = set(map(int, swin.strip().split()))
    own = set(map(int, sown.strip().split()))

    cnt = len(win.intersection(own))
    wat.append(cnt)
    if cnt > 0:
        res += 2**(cnt - 1)

print(res)

wut = [1] * len(wat)


for i in range(1, len(wat)):
    for j in range(i + 1, min(i + 1 + wat[i], len(wat))):
        wut[j] += wut[i]

print(sum(wut[1:]))
