# Day 16: Reindeer Maze

> [Full Problem Statement](https://adventofcode.com/2024/day/16)

*I'm still lazy to implement a proper data structure for 2D grid.*

## Part 1

Given another 2D grid with some obstacles, start cell, and end cells. The task
is to get the length of shortest part from start cell to end cell.

The cost of move from one cell to another is $1$ and the cost for changing
direciton by turning left or right is $1000$. We start facing right in the start
cell. What is the minimum cost to walk from start cell to end cell?

We can use any shortest path algorithm on weighted graph for this problem. I am
using Dijkstra's algorithm for my solution. One thing to note is about the
direction. Because the changing direction is affecting the cost, we must save
the cost in terms of position and direction instead of only position.

The time complexity of this solution is $O(\text{dijkstra})$ (I forget).

## Part 2

For this part, we have to count how many cell for **all** possible shortest
path from start cell to end cell.

We can just backtrack using DFS or BFS and checking the possible path using
stored cost from part 1. Everytime we move try to another cell, we check if the
difference of the cost is possible or not.

The time complexity of this solution is $O(\text{DFS} \lor \text{BFS})$.

> [Solution Code](./sol.py)

As usual, I am too lazy to implement proper data structure and only using
typedef. Because I need to store the cost in terms of `(position, direction)`, I
then create this monstrosity.

```cpp
...

typedef pair<int, int> pii;
typedef pair<pii, char> pos_dir;
typedef pair<int, pos_dir> dist_pos_dir;

...

priority_queue<dist_pos_dir, vector<dist_pos_dir>, greater<dist_pos_dir>> pq;
map<pos_dir, int> dist;

...
```

Never again.
