#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void printMatrix(int a[MAX][MAX], int r, int c, const char *name) {
    printf("\n%s :\n", name, r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%6d ", a[i][j]);
        printf("\n");
    }
}

int main() {
    FILE *f = fopen("Book2.csv", "r");
    if (!f) {
        printf("Khong mo duoc file!\n");
        return 1;
    }

    int A[MAX][MAX], B[MAX][MAX];
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    char line[520];

    //Ma trận 1
    fgets(line, sizeof(line), f); // bỏ dòng đầu
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "matran2", 7) == 0)
            break;

        c1 = 0;
        char *token = strtok(line, ",");
        while (token) {
            A[r1][c1++] = atoi(token);
            token = strtok(NULL, ",");
        }
        r1++;
    }

    //Ma trận 2
    while (fgets(line, sizeof(line), f)) {
        c2 = 0;
        char *token = strtok(line, ",");
        while (token) {
            B[r2][c2++] = atoi(token);
            token = strtok(NULL, ",");
        }
        r2++;
    }

    fclose(f);

    printMatrix(A, r1, c1, "Ma tran A");
    printMatrix(B, r2, c2, "Ma tran B");

    //Cộng trừ 2 ma trận
    if (r1 == r2 && c1 == c2) {
        int sum[MAX][MAX], diff[MAX][MAX];
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++) {
                sum[i][j] = A[i][j] + B[i][j];
                diff[i][j] = A[i][j] - B[i][j];
            }

        printMatrix(sum, r1, c1, "A + B");    //in ma tran
        printMatrix(diff, r1, c1, "A - B");   //in ma tran
    } else {
        printf("\nkhong the cong/tru 2 ma tran\n");
    }

    //Nhân 2 ma trận
    if (c1 == r2) {
        int mul[MAX][MAX] = {0};
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c2; j++)
                for (int k = 0; k < c1; k++)
                    mul[i][j] += A[i][k] * B[k][j];

        printMatrix(mul, r1, c2, "A * B"); //in ma tran
    } else {
        printf("\nKhong the nhan 2 ma tran\n"); 
    }

    return 0;
}