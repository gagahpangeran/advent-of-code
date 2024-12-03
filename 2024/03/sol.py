from sys import stdin
import re

s = "".join([s.strip() for s in stdin])

pat = r"mul\((\d+),(\d+)\)"
m = re.findall(pat, s)

res = 0
for a, b in m:
    res += int(a) * int(b)

print(res)

pat = r"do\(\)|don't\(\)|mul\((\d+),(\d+)\)"
m = re.finditer(pat, s)

do = True
res = 0

for r in m:
    if r.group() == "do()":
        do = True
    elif r.group() == "don't()":
        do = False
    elif do:
        res += int(r.group(1)) * int(r.group(2))

print(res)
