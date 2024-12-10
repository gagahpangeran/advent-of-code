# Day 10: Hoof It

> [Full Problem Statement](https://adventofcode.com/2024/day/10)

*Depth first search, but not so deep.*

## Part 1

Given 2D grid with size $n \times m$. Every cells are number between `0` to `9`.

Start from cell with number `0` and then move up, down, left, or right to next
cell that contain number 1 higher than current number until cell with number
`9`. Then count how many unique cell with number `9` that can be reached from
this cell with number `0`. We call this number a **score**.

The output is total sum of all **score**.

My solution is just do DFS in 2D grid and save the last position of cell with
number `9` into set, then count how many element in the set.

The maximum depth of DFS itself is `10` and we visit maximum `3` adjacent cells
in each visit, because we can't go back to previous cells. The exception is at
the start, we can visit maximum `4` adjacent cells.

Assumming the set insertion time complexity is $O(1)$. So, the time complexity
of this solution is $O(3^{10} n m)$ or without the constant factor is $O(nm)$.
But the constant factor is so big, it can't be ignored.

## Part 2

Basically the same as part 1 but we count the number of different path from cell
`0` to cell `9`.

I just modified a bit of the implementation from part 1 because the solution is
the same, just do DFS. So, the time complexity is also the same.

> [Solution Code](./sol.cpp)
