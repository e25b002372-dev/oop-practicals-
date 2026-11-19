# Practical 11: CSV student records

## Concept and observation
Format: positive integer ID,name without commas or newlines,integer marks 0–100; no header or quoted fields. Each run recreates students.csv with three examples. Get positions refer to input, put positions to output. The separate positions.txt example replaces the third byte without damaging a CSV record.

## Run on Mac
From this practical’s directory:
```sh
clang++ -std=c++17 -Wall -Wextra main.cpp -o demo
./demo
```
See output.txt for captured console output.
