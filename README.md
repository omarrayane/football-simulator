# Football Tournament Simulator

A simple console-based football tournament simulator written in C. This program allows you to simulate a round-robin football tournament with customizable teams and stadium locations.

## Features

- **Interactive Menu**: Choose to run the tournament or exit the program.
- **Stadium Selection**: Pick from famous stadiums around the world as the tournament venue.
- **Team Management**: Enter between 10 and 20 teams with custom names.
- **Round-Robin Scheduling**: Automatically generates a fair schedule where each team plays every other team once.
- **Match Simulation**: Randomly simulates match results with goals scored.
- **Statistics Tracking**: Calculates wins, draws, losses, points (3 for win, 1 for draw), and total goals.
- **Final Standings**: Displays a ranked table and announces the winner based on points, then goal difference.
- **Cross-Platform**: Works on Windows and Linux/macOS with appropriate console support.
- **Colored Output**: Uses ANSI colors for better readability (with Windows console API fallback).

## Requirements

- A C compiler such as `gcc`, `clang`, or MSVC.
- For Linux/macOS: An ANSI-capable terminal.
- For Windows: Standard Windows console (the program uses `windows.h` for colors and `Sleep` for delays).

## Building

### On Linux/macOS

```bash
gcc footsim.c -o footsim
```

### On Windows

```bash
gcc footsim.c -o footsim.exe
```

Or using MSVC:

```bash
cl footsim.c
```

## Usage

1. Run the compiled executable:
   ```bash
   ./footsim  # On Linux/macOS
   footsim.exe  # On Windows
   ```

2. From the menu, select option 1 to start the tournament.

3. Choose a stadium location from the list of 6 famous venues.

4. Enter the number of teams (10-20).

5. Input the names of each team.

6. The program will display the match schedule, simulate each match with a delay for dramatic effect, and finally show the league table with the winner.

## Example Output

```
******************************************
**    Welcome To our Tournament System  **
******************************************

Menu:
1. Run the program
2. Exit
Enter your choice: 1

Choose the location of the tournament:
1. Parc Des Princes, Paris
...
Enter your choice (1-6): 1
Welcome to Parc des Princes, Paris!

Enter the number of teams (10 to 20): 12
Enter the name of Team 1: Real Madrid
...
[Match simulations and final table]
```

## How It Works

- The tournament uses a round-robin format where each team plays every other team exactly once.
- Matches are simulated randomly, with each team having an equal chance of scoring goals (0-5 per match).
- Points are awarded: 3 for a win, 1 for a draw, 0 for a loss.
- The winner is determined by total points, with goal difference as a tiebreaker.

## Contributing

Feel free to fork the repository and submit pull requests for improvements or bug fixes.

