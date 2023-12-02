from sys import stdin

max_cubes = {
    "red": 12,
    "green": 13,
    "blue": 14
}

res1 = 0
res2 = 0

for s in stdin:
    game, colors = s.strip().split(": ")

    id = int(game.split()[-1])

    colors_set = colors.strip().split("; ")

    possible = True

    few_cube = {
        "red": 0,
        "green": 0,
        "blue": 0
    }

    for cubes in colors_set:
        cube = cubes.strip().split(", ")
        for c in cube:
            cnt, clr = c.split()
            possible = possible and int(cnt) <= max_cubes[clr]
            few_cube[clr] = max(few_cube[clr], int(cnt))

    if possible:
        res1 += id

    power = 1
    for k in few_cube:
        power *= few_cube[k]
    res2 += power

print(res1)
print(res2)