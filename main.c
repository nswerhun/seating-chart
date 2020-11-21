#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5 // <-- number of rows in table
#define COLS 5 // <-- number of columns in table
#define TABLE_COL_SPACE 10 // <-- max size of name
#define MAX_TABLE_VAL_LEN 5
#define EXIT_COMMAND "q"

#define MAX_NAME_LEN (TABLE_COL_SPACE+2) // !! DO NOT TOUCH !!

#define CHECK_FOR_EXIT(x) \
    x[strcspn(x, "\n")] = '\0'; \
    if (strcmp(x, EXIT_COMMAND) == 0) \
        goto exit;

int main(void) {

    char row_char[MAX_TABLE_VAL_LEN], column_char[MAX_TABLE_VAL_LEN], *chart[ROWS][COLS], *current_name;
    int row, column;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            chart[i][j] = malloc(MAX_NAME_LEN);
            if (chart[i][j] == NULL) {
                printf("Out of memory.");
                return 1;
            }
        }
    }

    printf("Type `%s` at any point to exit.\nROWS=%d COLS=%d MAX_NAME_LEN=%d-2\n\n", EXIT_COMMAND, ROWS, COLS, MAX_NAME_LEN);
    
    /* Get col */
    printf(" col: ");
    while (fgets(column_char, MAX_TABLE_VAL_LEN, stdin)) {
        CHECK_FOR_EXIT(column_char);
        column = atoi(column_char);
        if (column-1 < COLS) {
            /* Get row */
            printf(" row: ");
            while (fgets(row_char, MAX_TABLE_VAL_LEN, stdin)) {
                CHECK_FOR_EXIT(row_char);
                row = atoi(row_char);
                if (row-1 < ROWS) {
                    /* Get name */
                    printf("name: ");
                    current_name = chart[row-1][column-1];
                    fgets(current_name, MAX_NAME_LEN, stdin);
                    CHECK_FOR_EXIT(current_name);
                    break;
                } else {
                    printf("Out of bounds.\n");
                    printf(" row: ");
                    continue;
                }
            }

            /* Print chart */
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    printf("|%*s|", TABLE_COL_SPACE, chart[i][j]);
                }
                putchar('\n');
            }
        
            printf(" col: ");
        } else {
            printf("Out of bounds.\n");
            printf(" col: ");
            continue;
        }
    }

exit:
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            free(chart[i][j]);
        }
    }
    printf("\n\nFreed memory. Exiting.\n");
    return 0;
}
