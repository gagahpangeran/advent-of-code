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

for i in range(n):
    for j in range(m):
        if (i, j) not in visited:
            g[i][j] = '.'

cpos = {
    ('L', 'I'): [(0, 1), (-1, 0)],
    ('L', 'O'): [(0, -1), (1, 0), (1, -1)],
    ('J', 'I'): [(0, -1), (-1, 0)],
    ('J', 'O'): [(0, 1), (1, 0), (1, 1)],
    ('7', 'I'): [(0, -1), (1, 0)],
    ('7', 'O'): [(0, 1), (-1, 0), (-1, 1)],
    ('F', 'I'): [(0, 1), (1, 0)],
    ('F', 'O'): [(0, -1), (-1, 0), (-1, -1)],
}

inmv = {
    ('L', 'R'): cpos[('L', 'I')],
    ('L', 'L'): cpos[('L', 'O')],
    ('L', 'U'): cpos[('L', 'I')],
    ('L', 'D'): cpos[('L', 'O')],

    ('J', 'R'): cpos[('J', 'O')],
    ('J', 'L'): cpos[('J', 'I')],
    ('J', 'U'): cpos[('J', 'I')],
    ('J', 'D'): cpos[('J', 'O')],

    ('7', 'R'): cpos[('7', 'O')],
    ('7', 'L'): cpos[('7', 'I')],
    ('7', 'U'): cpos[('7', 'O')],
    ('7', 'D'): cpos[('7', 'I')],

    ('F', 'R'): cpos[('F', 'I')],
    ('F', 'L'): cpos[('F', 'O')],
    ('F', 'U'): cpos[('F', 'O')],
    ('F', 'D'): cpos[('F', 'I')],

    ('|', 'L'): [mv['L']],
    ('|', 'R'): [mv['R']],

    ('-', 'U'): [mv['U']],
    ('-', 'D'): [mv['D']],
}

innx = {
    ('L', 'R'): 'U',
    ('L', 'L'): 'D',
    ('L', 'U'): 'R',
    ('L', 'D'): 'L',

    ('J', 'R'): 'D',
    ('J', 'L'): 'U',
    ('J', 'U'): 'L',
    ('J', 'D'): 'R',

    ('7', 'R'): 'U',
    ('7', 'L'): 'D',
    ('7', 'U'): 'R',
    ('7', 'D'): 'L',

    ('F', 'R'): 'D',
    ('F', 'L'): 'U',
    ('F', 'U'): 'L',
    ('F', 'D'): 'R',
}

ins = 'R'

st = [spos]
visited = set()

inside = set()

while len(st) > 0:
    cur = st.pop()
    if cur in visited:
        continue

    visited.add(cur)
    (i, j) = cur
    pipe = g[i][j]

    assert ((pipe, ins) in inmv)

    for mm in inmv[(pipe, ins)]:
        (mi, mj) = mm
        (mmi, mmj) = (i + mi, j + mj)

        if 0 <= mmi < n and 0 <= mmj < m:
            if g[mmi][mmj] == '.':
                g[mmi][mmj] = 'i'
                inside.add((mmi, mmj))

    if (pipe, ins) in innx:
        ins = innx[(pipe, ins)]

    for move in nx[pipe]:
        (mi, mj) = mv[move]
        (nxi, nxj) = (i+mi, j+mj)

        if 0 <= nxi < n and 0 <= nxj < m:
            if (nxi, nxj) not in visited:
                nx_pipe = g[nxi][nxj]
                if nx_pipe in nxp[move]:
                    st.append((nxi, nxj))

vis = set()

for pin in inside:
    qu = [pin]

    while len(qu) > 0:
        cur = qu.pop(0)

        if cur in vis:
            continue

        vis.add(cur)
        (ci, cj) = cur

        for i in [-1, 0, 1]:
            for j in [-1, 0, 1]:
                (ni, nj) = (ci + i, cj + j)

                if 0 <= ni < n and 0 <= nj < m:
                    if (ni, nj) not in visited:
                        if g[ni][nj] == '.':
                            qu.append((ni, nj))
                            g[ni][nj] = 'i'

res = 0

for i in g:
    for j in i:
        if j == 'i':
            res += 1

print(res)

# delete exit below to see cool stuff
exit()

ch = {
    '|': '│',
    '-': '─',
    'L': '└',
    'J': '┘',
    '7': '┐',
    'F': '┌',
    '.': '.',
}

for i in range(n):
    for j in range(m):
        if (i, j) in visited:
            g[i][j] = ch[g[i][j]]

for s in g:
    print(''.join(s))
