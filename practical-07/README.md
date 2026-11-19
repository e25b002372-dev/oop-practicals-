# Practical 07: Compile-time overloading

## Concept and observation
Function overloads select add by argument types. Operator overloading lets a+b add the components of two complex numbers without exposing that arithmetic at the call site. Unlike virtual dispatch, overload selection uses compile-time types.

## Run on Mac
From this practical’s directory:
```sh
clang++ -std=c++17 -Wall -Wextra main.cpp -o demo
./demo
```
See output.txt for captured console output.
