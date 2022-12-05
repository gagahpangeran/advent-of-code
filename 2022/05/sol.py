from sys import stdin

n = int(input())

v = []
u = []
for _ in range(n):
    s = input()
    v.append(s.split())
    u.append(s.split())

for s in stdin:
    _, mv, __, fr, ___, to = s.strip().split()
    mv = int(mv)
    fr = int(fr) - 1
    to = int(to) - 1

    sem = []
    for _i in range(mv):
        v[to].append(v[fr].pop())
        sem.append(u[fr].pop())
    sem.reverse()
    u[to].extend(sem)


for st in v:
    print(st[-1], end='')
print()

for st in u:
    print(st[-1], end='')
print()
