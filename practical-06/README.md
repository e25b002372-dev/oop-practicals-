# Practical 06: Runtime polymorphism

## Concept and observation
Shape has a pure virtual area function and cannot be instantiated. report accepts a Shape reference; the actual object selects the area calculation at runtime.

## Run on Mac
From this practical’s directory:
```sh
clang++ -std=c++17 -Wall -Wextra main.cpp -o demo
./demo
```
See output.txt for captured console output.
