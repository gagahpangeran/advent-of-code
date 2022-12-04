from sys import stdin


res = 0
pair = 0
nonov = 0
for s in stdin:
    pair += 1
    a, b = s.strip().split(',')
    la, ra = map(int, a.split('-'))
    lb, rb = map(int, b.split('-'))

    if (la <= lb <= rb <= ra) or (lb <= la <= ra <= rb):
        res += 1

    if (ra < lb) or (rb < la):
        nonov += 1

print(res)
print(pair - nonov)
