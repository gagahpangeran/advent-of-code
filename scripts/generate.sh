#!/usr/bin/env bash

# This script should be run from root directory of this repo
# Please read instruction how to use this script in the README.md file

day=$(date +%d)
year=$(date +%Y)
root_dir=$(pwd)

if [ -n "$1" ]; then
  day=$1
fi

if [ -n "$2" ]; then
  year=$2
fi

gen_dir="$root_dir/$year/$day/"

if [ -d "$gen_dir" ]; then
  echo "$gen_dir already exist!"
  exit 0
fi

mkdir "$gen_dir"
touch "$gen_dir/sample.in"
touch "$gen_dir/input.in"
cp "$root_dir/templates/sol.cpp" "$gen_dir"
cp "$root_dir/templates/sol.py" "$gen_dir"

echo "$gen_dir is created!"
