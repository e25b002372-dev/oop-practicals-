# Practical 09: Generic stack

## Concept and observation
Stack<T> reuses one implementation for int, float and string. Two pushes followed by two pops return the newest first. A third pop throws instead of accessing an empty vector.

## Run on Mac
From this practical’s directory:
```sh
clang++ -std=c++17 -Wall -Wextra main.cpp -o demo
./demo
```
See output.txt for captured console output.
