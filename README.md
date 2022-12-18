# Advent of Code

GPR's solution for AoC.

Most of it are written in C++ and Python.

## Problem Statement

All problems/puzzles statement can be accessed on [Advent of Code Website][AoC].

## How To Run

### C++ Solution

Assume you already install [gcc][gcc] in your system.

```sh
g++ <solutionfile> -o <fileoutput>
```
Then run the `fileoutput` with `sample.in` or `input.in` as file input.

```sh
./fileoutput < <fileinput>
```

*Example to compile and run solution of [2022 day 1][day1]:*

**Compile**

```sh
g++ sol.cpp -o sol
```

**Run the sample input**

```sh
./sol < sample.in
```

**Run the real problem input**

```sh
./sol < input.in
```

### Python solution

Assume you already install [python][python] in your system.

Run the `solutionfile` with `sample.in` or `input.in` as file input.

```sh
python <solutionfile> < <fileinput>
```

*Example to run solution of [2022 day 4][day4]:*

**Run the sample input**

```sh
python sol.py < sample.in
```

**Run the real problem input**

```sh
python sol.py < input.in
```

## Disclaimer

Solution in this repo may not be the best or readable.

[AoC]: https://adventofcode.com
[gcc]: https://gcc.gnu.org
[day1]: ./2022/01/sol.cpp
[python]: https://www.python.org
[day4]: ./2022/04/sol.py