#include <stdio.h>

int main() {
    int row;
    printf("Enter the number of rows: ");
    scanf("%d", &row);

    int pascal[row][row];  // fixed 2D array

    for (int i = 0; i < row; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            } else {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }

    // Print with spacing
    for (int i = 0; i < row; i++) {
        for (int s = 0; s < row - i - 1; s++) {
            printf("  ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%4d", pascal[i][j]);
        }
        printf("\n");
    }

    return 0;
}

