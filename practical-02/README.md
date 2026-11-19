# Practical 02: BankAccount and access control

## Concept and observation
A private balance cannot be changed directly by main. Public withdraw validates the amount before updating it. The same request succeeds for A01 and fails for A02.

## Run on Mac
From this practical’s directory:
```sh
clang++ -std=c++17 -Wall -Wextra main.cpp -o demo
./demo
```
See output.txt for captured console output.
