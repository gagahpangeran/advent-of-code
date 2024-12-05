from sys import stdin

pos = []
pages = []

for s in stdin:
    s = s.strip()
    if "|" in s:
        pos.append(tuple(map(int, s.split("|"))))
    elif "," in s:
        pages.append(list(map(int, s.split(","))))


def chk(page):
    ok = True
    n = len(page)
    for i in range(n - 1):
        for j in range(i+1, n):
            a = page[i]
            b = page[j]
            if (b, a) in pos:
                ok = False
                page[i], page[j] = b, a
    return ok


res = 0
res2 = 0
for page in pages:
    mid = len(page) // 2
    if chk(page):
        res += page[mid]
    else:
        res2 += page[mid]

print(res)
print(res2)
