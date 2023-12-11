from sys import stdin

g = []
for s in stdin:
    g.append(list(s.strip()))

n = len(g)
m = len(g[0])

spos = (0, 0)
for i in range(n):
    for j in range(m):
        if g[i][j] == 'S':
            spos = (i, j)

mv = {
    'U': (-1, 0),
    'D': (1, 0),
    'L': (0, -1),
    'R': (0, 1),
}

nx = {
    '|': ['U', 'D'],
    '-': ['L', 'R'],
    'L': ['U', 'R'],
    'J': ['U', 'L'],
    '7': ['D', 'L'],
    'F': ['D', 'R'],
}

nxp = {
    'U': ['7', 'F', '|'],
    'D': ['L', 'J', '|'],
    'L': ['L', 'F', '-'],
    'R': ['7', 'J', '-'],
}

# NOTE: change this to 'F' for sample
START_PIPE = 'J'

st = [spos]
visited = set()
(si, sj) = spos
g[si][sj] = START_PIPE
is_loop = False
step = 0

while len(st) > 0:
    cur = st.pop()
    if cur in visited:
        continue

    step += 1
    visited.add(cur)
    (i, j) = cur
    pipe = g[i][j]

    for move in nx[pipe]:
        (mi, mj) = mv[move]
        (nxi, nxj) = (i+mi, j+mj)

        if 0 <= nxi < n and 0 <= nxj < m:
            if (nxi, nxj) not in visited:
                nx_pipe = g[nxi][nxj]
                if nx_pipe in nxp[move]:
                    st.append((nxi, nxj))
            else:
                if (nxi, nxj) == spos:
                    is_loop = True

assert (is_loop)
print((step+1)//2)
