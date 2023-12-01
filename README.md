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

### Script

Currently there is one script to generate solution template. You should run the
script from root directory of this repo.

```bash
./scripts/generate.sh <day> <year>
```

The `day` and `year` arguments are optional. If you do not provide it, it will
automatically using current day and year based on your local time. The script
will be failed if the directory is already exists.

*All the example assume your local time is **2023-12-07**.*

**Example**

```bash
./scripts/generate.sh
```

The output of the script will be something like below.

```bash
/home/user/gpr/advent-of-code/2023/07/ is created!
```

The output when the directory is exists.

```bash
/home/user/gpr/advent-of-code/2023/07/ already exist!
```

**Example with day argument**

```bash
./scripts/generate.sh 13
```

```bash
/home/user/gpr/advent-of-code/2023/13/ is created!
```

**Example with day and year argument**

```bash
./scripts/generate.sh 27 2022
```

```bash
/home/user/gpr/advent-of-code/2022/27/ is created!
```

## Disclaimer

Solution in this repo may not be the best or readable.

[AoC]: https://adventofcode.com
[gcc]: https://gcc.gnu.org
[day1]: ./2022/01/sol.cpp
[python]: https://www.python.org
[day4]: ./2022/04/sol.py