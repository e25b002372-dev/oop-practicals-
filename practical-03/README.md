# Practical 03: Constructors and the Rule of Five

## Concept and observation
A copy gets its own array; changing the original leaves both copies unchanged. A move transfers the pointer and resets the source. See memory-check.txt.

## Run on Mac
From this practical’s directory:
```sh
clang++ -std=c++17 -Wall -Wextra main.cpp -o demo
./demo
```
See output.txt for captured console output.
