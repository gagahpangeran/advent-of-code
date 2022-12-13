from sys import stdin
from functools import cmp_to_key

packets = []

for s in stdin:
    s = s.strip()
    if s == "":
        continue

    packets.append(eval(s))


def check(a, b):
    assert (type(a) is list)
    assert (type(b) is list)

    for i in range(min(len(a), len(b))):
        x = a[i]
        y = b[i]
        tx = type(x)
        ty = type(y)

        if (tx is int) and (ty is int):
            if x < y:
                return True
            elif x > y:
                return False
        elif (tx is list) and (ty is list):
            res = check(x, y)
            if res is not None:
                return res
        else:
            if tx is int:
                x = [x]
            elif ty is int:
                y = [y]

            res = check(x, y)
            if res is not None:
                return res

    if len(a) < len(b):
        return True

    if len(a) > len(b):
        return False

    return None


res = 0
for i in range(0, len(packets), 2):
    a = packets[i]
    b = packets[i + 1]
    ok = check(a, b)
    assert (ok is not None)
    if ok:
        res += (i // 2) + 1
print(res)

div1 = [[2]]
div2 = [[6]]

packets.append(div1)
packets.append(div2)


def compare(a, b):
    chk = check(a, b)
    assert (chk is not None)
    return -1 if chk else 1


spac = sorted(packets, key=cmp_to_key(compare))

u = 0
v = 0
for i in range(len(spac)):
    if spac[i] == div1:
        u = i + 1
    elif spac[i] == div2:
        v = i + 1

key = u * v
assert (key != 0)
print(key)
