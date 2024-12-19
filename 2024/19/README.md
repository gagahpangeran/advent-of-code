# Day 19: Linen Layout

> [Full Problem Statement](https://adventofcode.com/2024/day/19)

*1 + 1 = 11*

## Part 1

Given a list of string and bunch of target string. The task is to check if we
can construct the target string by concatenating any string from the list.

The output is how many string that can be constructed by this method.

My first intuition when reading this problem is the solution is some kind of
dynamic programing problem.

Let `s` is the target string. We have state `dp[i]` that indicates whether the
substring `s[0:i]` can be constructed using the strings from the list. Let `m`
is the length of that string in the list, we then check whether substring
`s[i-m:m]` is equal. Then we can check whether previous substring `s[0:i-m]`
can be constructed using the strings from the list by checking the value of
`dp[i-m]`. Finally we get value of `dp[i] = s[i-m:m] == b and dp[i-m] == true`.

Let $n$ is the length of the target string and $k$ is the number of the strings
in the list. The time complexity of this solution is $O(nk)$, or $O(nkm)$ if we assume the complexity to comparing two string with length $m$ is $O(m)$.

## Part 2

Basically the same as part 1, but this time the task is to count how many ways
to construct the target string.

I just modify the state `dp[i]` previous solution to count the number of ways
to construct the string, instead of just indicates whether the string can be
constructed.

Time complexity of this solution is the same as before.

> [Solution Code](./sol.cpp)
