# Practical 12: Library management system

## Concept and observation
For a librarian tracking books and loans. Add books, list the catalog, search by ID, issue and return books. Data is saved after each change and loaded on restart. Unknown IDs, duplicate IDs, repeat loans and invalid returns are rejected. Storage: one tab-separated row per book, ID/title/author/available (1 or 0). Single-user console application.

## Run on Mac
From this practical’s directory:
```sh
clang++ -std=c++17 -Wall -Wextra main.cpp -o demo
./demo
```
See output.txt for captured console output.

## Class diagram
```text
CatalogItem (id, title)
    △
    │ inherits
   Book (author, availability; issue/return state checks)
    ▲
    │ contains 0..* books, indexed by ID
 Library (add, find, list, change, load, save)
```
LibraryError extends runtime_error and reports catalog errors.

## Demo
The included library.tsv is the saved catalog. Run `list` to view it. To reproduce output.txt from an empty catalog, use a fresh directory without library.tsv, run the program with sample-input.txt as stdin, then restart and enter search, B01, return, B01, list, quit on separate lines. The second session verifies persistence.
