from sys import stdin


def parse_xy(ss):
    res = [i.replace("x=", "").replace("y=", "")
           .replace(",", "") for i in ss.split()]

    return int(res[-2]), int(res[-1])


sensors = []
dist = {}


for s in stdin:
    sn, bc = s.strip().split(":")
    sx, sy = parse_xy(sn)
    bx, by = parse_xy(bc)

    d = abs(sx - bx) + abs(by - sy)

    sensors.append((sx, sy))
    dist[(sx, sy)] = d

sensors.sort()

# maxy = 20
maxy = 4*10**6

for cy in range(maxy+1):
    rg = []
    for sx, sy in sensors:
        d = dist[(sx, sy)]
        dy = abs(sy - cy)
        dx = d - dy
        lx = sx - dx
        rx = sx + dx
        if dx >= 0:
            rg.append((max(0, lx), min(4*10**6, rx)))

    rg.sort()
    rgs = []
    for lx, rx in rg:
        if len(rgs) > 0 and lx - rgs[-1][1] <= 1:
            rgs[-1][0] = min(lx, rgs[-1][0])
            rgs[-1][1] = max(rx, rgs[-1][1])
        else:
            rgs.append([lx, rx])

    if len(rgs) > 1:
        assert (len(rgs) == 2)
        la, ra = rgs[0]
        lb, rb = rgs[1]
        assert (lb - ra == 2)
        cx = ra + 1
        print(cx * (4*10**6) + cy)
        break
