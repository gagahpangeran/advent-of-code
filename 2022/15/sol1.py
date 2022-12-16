from sys import stdin


def parse_xy(ss):
    res = [i.replace("x=", "").replace("y=", "")
           .replace(",", "") for i in ss.split()]

    return int(res[-2]), int(res[-1])


sensors = []
beacons = []

ty = 2000000
# ty = 10
ranges = []


for s in stdin:
    sn, bc = s.strip().split(":")
    sx, sy = parse_xy(sn)
    bx, by = parse_xy(bc)

    d = abs(sx - bx) + abs(by - sy)

    dy = abs(sy - ty)
    dx = d - dy
    if dx >= 0:
        ranges.append((sx - dx, sx + dx))

    sensors.append((sx, sy))
    beacons.append((bx, by))

ranges.sort()
allr = [list(ranges[0])]

for i in range(1, len(ranges)):
    if ranges[i][0] <= allr[-1][1]:
        allr[-1][1] = max(allr[-1][1], ranges[i][1])
    else:
        allr.append(list(ranges[i]))

res = 0
for a, b in allr:
    res += b - a + 1

    for sx, sy in set(sensors):
        if sy == ty and a <= sx <= b:
            res -= 1

    for bx, by in set(beacons):
        if by == ty and a <= bx <= b:
            res -= 1

print(res)
