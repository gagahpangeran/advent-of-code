# Day 7: Bridge Repair

> [Full Problem Statement](https://adventofcode.com/2024/day/7)

*Exponential time complexity is not so bad.*

## Part 1

Given $n$ lines of input. Each line contains a **target number** and a
**list of numbers** that contains $m$ numbers.

The task is to check if we can get the **target number** from this
**list of numbers** using only **add** and **multiply** operator or not. We
call this **target number** *valid* if we can make the operation to get it.

There is no precedence in this operation, so the operation is always evaluated
from left to right. Also the position of the numbers in this list can't be
changed.

The output is the sum of all *valid* **target number** from all lines.

My solution is just bruteforce it, by trying every possible operations.

The implementation is using iterative approach by converting number into binary.
`0` is for **add** and `1` is for **multiply**. I also add some pruning by
breaking early when current result of the operation is more than the
**target number**.

Time complexity is $O(n \cdot 2^m)$.

## Part 2

Basically the same as part 1, but this time we can use new **concat** operation.
This **concat** operation basically just concat two number like string.

Now we have three operator, I just do the same as part 1 and add this new
operation.

Time complexity is $O(n \cdot 3^m)$.

> [Solution Code](./sol.py)

The runtime is not so bad.

For part 1, it runs fast for about 0.29 seconds. But for part 2, it runs for
about 20 seconds.
