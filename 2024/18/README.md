# Day 18: RAM Run

> [Full Problem Statement](https://adventofcode.com/2024/day/18)

*Another shortest path problem.*

## Part 1

Given list of coordinate obstacle for 2D grid with size $n \times m$. The task
is to find the length of shortest path from coordinate $(0,0)$ to $(n,m)$ if the
first $k$ obstacle from the list is placed on the grid.

The solution is trivial, just do any kind of shortest path algorithm. I'm using
BFS for my solution.

The complexity of this solution is $O(nm)$.

## Part 2

For this part, I need to find the first obstacle than can block any path from
$(0,0)$ to $(n,m)$.

My solution is to binary search the value of $k$, place the first $k$ obstacle
on the grid, then do BFS like before.

Assuming the maximum number of coordinate in the list is $l$, the complexity of
this solution is $O((k+nm)\log{l})$.

> [Solution Code](./sol.cpp)
