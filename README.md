# Tournament Simulator (C)

A simple console-based football tournament simulator written in C.  
It lets you:

- Choose a famous stadium as the tournament location
- Enter between 10 and 20 teams
- Automatically generate a round-robin schedule
- Randomly simulate match results
- Show a final score table and announce the winner

The program uses ANSI colors (and Windows console APIs when needed) to make the output more readable.

---

## Features

- Cross-platform (Windows / Linux)
- Colored console output
- Round-robin match scheduling
- Random goals and match results
- Automatic calculation of:
  - Wins / Draws / Losses  
  - Points (3 for win, 1 for draw)  
  - Total goals scored
- Final winner announcement based on points (then goals)

---

## Requirements

- C compiler (e.g. `gcc`, `clang`, or MSVC)
- For Linux / macOS:
  - ANSI-capable terminal
- For Windows:
  - Windows console (uses `windows.h` and `Sleep`)

---

## Building

Assume the file is named `tournament.c`.

### On Linux / macOS

```bash
gcc tournament.c -o tournament

