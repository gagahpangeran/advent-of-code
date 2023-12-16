import re


def hash(s):
    val = 0

    for c in s:
        val += ord(c)
        val *= 17
        val %= 256

    return val


s = input()

ls = s.split(',')

res = 0
for l in ls:
    res += hash(l)
print(res)

mp = [[] for _ in range(256)]

for l in ls:
    label, num = re.split(r'=|-', l)
    hs = hash(label)

    idx = -1
    for i in range(len(mp[hs])):
        if mp[hs][i][0] == label:
            idx = i
            break

    if num != '':
        if idx == -1:
            mp[hs].append((label, int(num)))
        else:
            mp[hs][idx] = (label, int(num))
    else:
        if idx != -1:
            mp[hs].pop(idx)


res2 = 0
for i in range(len(mp)):
    for j in range(len(mp[i])):
        res2 += (i + 1) * (j + 1) * mp[i][j][1]

print(res2)
