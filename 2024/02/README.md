# Day 2: Red-Nosed Reports

> [Full Problem Statement](https://adventofcode.com/2024/day/2)

*Just remove it one by one.*

## Part 1

Given $n$ lines with each line contains list of $m$ numbers.

The task is to check if the list either all increasing or all decreasing with
any two adjacent number differ by at least $1$ and at most $3$.

The output is how many of this list that are valid.

Sounds easy to implement.

The time complexity for my solution is $O(nm)$.

## Part 2

For this part, it's the same as before but I can remove at most **one** number
from the list and then check if it is valid or not.

My solution is just remove one number at a time and then check it.

The time complexity for this solution is $O(nm^2)$.

> [Solution Code](./sol.cpp)
