# Practical 10: Banking exceptions

## Concept and observation
InvalidAmount rejects zero or negative withdrawals; InsufficientFunds rejects positive withdrawals above the balance. Both checks occur before subtraction, leaving failed transactions without side effects.

## Run on Mac
From this practical’s directory:
```sh
clang++ -std=c++17 -Wall -Wextra main.cpp -o demo
./demo
```
See output.txt for captured console output.
