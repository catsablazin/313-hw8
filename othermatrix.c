#include <stdio.h>
#define ROW_A 2
#define COL_A 2
#define ROW_B 2
#define COL_B 3
#define ROW_C 2
#define COL_C 3


void transpose(int a[ROW_C][COL_C], int b[COL_C][ROW_C]) {
  for (int i = 0; i < ROW_C; i++)
    for (int j = 0; j < COL_C; j++)
      b[j][i] = a[i][j];
}


void scalar(int rows, int cols, int mat[rows][cols], int scale) {
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j){
      mat[i][j] *= scale;
    }
}


void multiply(int a[ROW_B][COL_B], int b[COL_B][COL_A], int result[ROW_B][COL_A]) {
  for (int i = 0; i < ROW_B; i++){
    for (int j = 0; j < COL_A; j++) {
      for (int k = 0; k < COL_B; k++)
        result[i][j] += a[i][k] * b[k][j];
    }
  }
}


void add(int a[ROW_A][COL_A], int b[ROW_A][COL_A], int result[ROW_A][COL_A]) {
  for (int i = 0; i < ROW_A; i++){
    for (int j = 0; j < COL_A; j++)
      result[i][j] = a[i][j] + b[i][j];
  }
}


void print(int rows, int cols, int mat[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }
}


int main() {
  int A[ROW_A][COL_A] = {{6, 4}, {8, 3}};
  int B[ROW_B][COL_B] = {{1, 2, 3}, {4, 5, 6}};
  int C[ROW_C][COL_C] = {{2, 4, 6}, {1, 3, 5}};

  int C_transposed[COL_C][ROW_C] = {{0, 0}, {0, 0}, {0,0}};
  int product[ROW_B][COL_A] = {{0, 0}, {0, 0}};
  int D[ROW_A][COL_A];

  scalar(ROW_B, COL_B, B, 3);
  transpose(C, C_transposed);
  multiply(B, C_transposed, product);
  add(A, product, D);

  print(ROW_A, COL_A, D);

  return 0;
}
