# Day 1: Historian Hysteria

> [Full Problem Statement](https://adventofcode.com/2024/day/1)

*Number counting.*

## Part 1

Given two lists of integer (left list and right list) with the same $n$ size.

The task is to get the difference between 1st smallest number from both list,
difference between 2nd smallest number from both list, and so on.

The output is the sum of all of the differences.

The solution is straightforward. Just sort both list and get the difference
between 1st number, 2nd number, and so on.

So the time complexity is $O(n \log{n})$.

## Part 2

For this part, the task is to multiply each number from left list with how many
occurence that number in the right list.

The output is the sum of all of this multiplication.

The solution is also straightforward, just save the count of the occurence to
array or map.

The time complexity is $O(n)$ or $O(n \log{n})$ depending on the implementation.

> [Solution Code](./sol.cpp)
