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
      a[j][i] = b[i][j];
}

void scalar_multiply(int rows, int cols, int mat[rows][cols], int scale) {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      mat[i][j] *= scale;
}

void multiply(int a[ROW_B][COL_B], int b[COL_B][COL_A], int result[ROW_B][COL_A]) {
  for (int i = 0; i < ROW_B; i++){
    for (int j = 0; j < COL_A; j++) {
      result[i][j] = 0;
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

void print_matrix(int rows, int cols, int mat[rows][cols]) {
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
  
  int B_scaled[ROW_B][COL_B];
  int C_transposed[COL_C][ROW_C];
  int product[ROW_B][COL_A];
  int D[ROW_A][COL_A];

  for (int i = 0; i < ROW_B; i++)
    for (int j = 0; j < COL_B; j++)
      B_scaled[i][j] = B[i][j];
  
  scalar_multiply(ROW_B, COL_B, B_scaled, 3);
  transpose(C, C_transposed);
  multiply(B_scaled, C_transposed, product);

  add(A, product, D);

  printf("Matrix D:\n");
  print_matrix(ROW_A, COL_A, D);

  return 0;
}
