from sys import stdin


def pp(v):
    for s in v:
        print(''.join(s))
    print()


def transpose(v):
    return list(map(list, zip(*v)))


def rotate(v):
    return transpose(v[::-1])


def roll(v):
    t = transpose(v)

    for i in range(len(t)):
        cubes = []
        for j in range(len(t[i])):
            if t[i][j] == '#':
                cubes.append(j)

        cubes.insert(0, -1)
        cubes.append(len(t[i]))

        for j in range(len(cubes)-1):
            a = cubes[j]+1
            b = cubes[j+1]

            cnt = t[i][a:b].count('O')
            for k in range(a, b):
                if cnt > 0:
                    t[i][k] = 'O'
                else:
                    t[i][k] = '.'
                cnt -= 1

    r = transpose(t)
    return r


def count(v):
    res = 0
    for i in range(len(v)):
        res += v[i].count('O') * (len(v)-i)
    return res


def cycle(v):
    n = roll(v)

    w = roll(rotate(n))

    s = roll(rotate(w))

    e = roll(rotate(s))

    return rotate(e)


g = []
for s in stdin:
    g.append(list(s.strip()))

r = roll(g)

res = count(r)

print(res)

c = g

target = 10**9

all_cnt = []

for i in range(target):
    c = cycle(c)
    cnt = count(c)
    all_cnt.append(cnt)

    if all_cnt.count(cnt) >= 3 and i > 100:
        pos = []
        for j in range(len(all_cnt)):
            if all_cnt[j] == cnt:
                pos.append(j)

        if pos[-1] - pos[-2] == pos[-2] - pos[-3] == pos[1] - pos[0]:
            a = pos[0]
            b = pos[1] - pos[0]
            mul = (target - a) // b
            rem = target - (a + b * mul)
            print(all_cnt[pos[-2] + rem - 1])
            break
