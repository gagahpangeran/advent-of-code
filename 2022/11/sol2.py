from sys import stdin

items = []
ops = []
tests = []
act = []

idx = -1

for s in stdin:
    s = s.strip()

    if s.startswith("Monkey"):
        idx = int(s.split()[1].replace(":", ""))
    elif s.startswith("Starting"):
        it = [[[int(i.strip()), idx]] for i in s.split(":")[1].split(',')]
        items.append(it)
    elif s.startswith("Operation"):
        op = s.split()[-2:]
        ops.append(op)
    elif s.startswith("Test"):
        tests.append(int(s.split(" ")[-1]))
    elif s.startswith("If"):
        next = int(s.split()[-1])
        if "true" in s:
            act.append([next])
        else:
            act[idx].insert(0, next)

rounds = 10000
inspect = [0 for _ in range(idx+1)]
nnn = [[] for _ in range(idx+1)]

memo = {}


def check(worry, m):
    key = (tuple(worry[0]), m)

    start = 1
    res = worry[0][0]
    if key in memo:
        start, res = memo[key]

    for i in range(start, len(worry)):
        op = worry[i][0]
        num = worry[i][1]

        if op == "+":
            res = (res + int(num)) % m
        elif op == "*":
            if num == "old":
                res = (res * res) % m
            else:
                res = (res * int(num)) % m

    memo[key] = [len(worry), res]

    return res == 0


for round in range(rounds):
    for i in range(idx+1):
        for j in range(len(items[i])):
            inspect[i] += 1

            worry = items[i][0]
            del items[i][0]

            worry.append(ops[i])
            result = check(worry, tests[i])

            next = act[i][result]
            items[next].append(worry)


inspect.sort(reverse=True)
print(inspect[0] * inspect[1])
