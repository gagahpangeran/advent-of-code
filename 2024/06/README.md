# Day 6: Guard Gallivant

> [Full Problem Statement](https://adventofcode.com/2024/day/6)

*Stuck in a loop.*

## Part 1

Given 2D grid with size $n \times m$. This grid contains character `.` (empty
cell), `#` (cell with obstacle), and `^` (starting cells with direction up).

The task is to simulate a guard walks on this grid from starting position and
direction until it walks outside the grid. Each time the guard meet obstacle
cell in front of it, then it turns right 90 degrees.

The output is how many distinct cells do the guard visit in this grid.

Seems simple enough, we can just implement by simulate the walking. Then save
the visited cells into set and output the size of the set.

I don't know about the complexity of this solution. Maybe $O(nm)$ because the
upper bound is when we visit all of the cells on the grid.

## Part 2

This part is we must place exactly **one** obstacle in any empty cell to make
the guard can't walk outside the grid. In other words, the guard will walk in
the close loop.

My solution is to place the new obstacle in any cells that the guard already
visited before from part 1 and then check if the guard walks in infinite loop.

The implementation is just count how many step the guard already walk and check
if it already reach $n \times m$ step as a limit. I just assume this means the
guard is walking in the close loop.

I assume there will be maximum $n \times m$ visited cell after walking from
part 1. Because we try all of this possibility to place a new obstacle and then
do the walk again, I assume the complexity of this solution is $O((nm)^2)$

> [Solution Code](./sol.cpp)

When I try to implement part 2, I stuck with wrong answer many times. I forget
to handle the case when the guard turn right, there is possibility it can turn
right again because there are obstacle again after it turns.

The runtime of the program is very fast. It's about 0.15 seconds.
