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
        it = [int(i.strip()) for i in s.split(":")[1].split(',')]
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

rounds = 20
inspect = [0 for _ in range(idx+1)]

for _ in range(rounds):
    for i in range(idx+1):
        for j in range(len(items[i])):
            inspect[i] += 1
            worry = items[i][0]
            del items[i][0]

            num = worry if ops[i][1] == "old" else int(ops[i][1])

            if ops[i][0] == "*":
                worry *= num
            elif ops[i][0] == "+":
                worry += num

            worry = worry // 3
            result = worry % tests[i] == 0
            items[act[i][result]].append(worry)


inspect.sort(reverse=True)
print(inspect[0] * inspect[1])
