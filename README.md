# seating-chart
A program that allows you to create and modify information in a table. Inspiration came from Ryan Gade. Thank you Ryan Gade.

## Building
Just run `make`, then `./seating-chart` (on \*nix)

## Config
See `main.c`:
```c
#define ROWS 5 // <-- number of rows in table
#define COLS 5 // <-- number of columns in table
#define TABLE_COL_SPACE 10 // <-- max size of name
#define MAX_TABLE_VAL_LEN 5
#define EXIT_COMMAND "q"
```
Pretty self-explanatory. `MAX_TABLE_VAL_LEN` is the maximum amount of digits `ROWS` and `COLS` can have, plus 1. By default it is 5, so the max digits `ROWS` and `COLS` can have is 4, i.e. 9999.

> Honestly, I think Mike Bloomberg is going to win the election.
*-- Genius, Ryan Gade*
