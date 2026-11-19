# Practical 08: Singleton settings

## Concept and observation
Flow: Editor → Settings::instance() ← Preview. Both clients see one configuration, so changes stay consistent. The trade-off is shared mutable state that makes tests harder to isolate.

## Run on Mac
From this practical’s directory:
```sh
clang++ -std=c++17 -Wall -Wextra main.cpp -o demo
./demo
```
See output.txt for captured console output.
