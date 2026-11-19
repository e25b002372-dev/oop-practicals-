# Practical 05: Single and multilevel inheritance

## Concept and observation
Diagram: Person ← Student ← GraduateStudent (arrows point to the base). Student reuses the public Person display function, not its private fields. GraduateStudent similarly reuses Student display and adds the research topic.

## Run on Mac
From this practical’s directory:
```sh
clang++ -std=c++17 -Wall -Wextra main.cpp -o demo
./demo
```
See output.txt for captured console output.
