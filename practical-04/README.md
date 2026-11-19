# Practical 04: RAII and smart pointers

## Concept and observation
A raw pointer alone does not say who must delete the object. unique_ptr transfers sole ownership; shared_ptr lets the editor and preview share a theme. Their scope controls destruction. See memory-check.txt.

## Run on Mac
From this practical’s directory:
```sh
clang++ -std=c++17 -Wall -Wextra main.cpp -o demo
./demo
```
See output.txt for captured console output.
