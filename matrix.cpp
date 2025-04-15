#include <iostream>
#include <vector>

typedef vector<vector<int>> Matrix;

Matrix transpose(const Matrix& m) {
  //looking through the matrix
  int rows = m.size();
  int cols = m[0].size();
  
  Matrix result(cols, vector<int>(rows));
  
  for (int i = 0; i < rows; ++i){
      for (int j = 0; j < cols; ++j)
        result[j][i] = m[i][j];
  }
    
  return result;
}


Matrix multiply(const Matrix& a, const Matrix& b) {
  int rows = a.size()
  int cols = b[0].size()
  int innerRows = a[0].size();
  
  Matrix result(rows, vector<int>(cols, 0));
  
  for (int i = 0; i < rows; ++i){
      for (int j = 0; j < cols; ++j){
          for (int k = 0; k < inner; ++k)
                result[i][j] += a[i][k] * b[k][j];
      }
  }
  
    return result;
}

Matrix scalar(const Matrix& m, int scale) {
    int rows = m.size();
    int cols = m[0].size();
  
    Matrix result(rows, vector<int>(cols));
  
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j)
            result[i][j] = m[i][j] * scale;
    }
    return result;
}

Matrix add(const Matrix& a, const Matrix& b) {
  int rows = a.size();
  int cols = a[0].size();

  Matrix result(rows, vector<int>(cols));

  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < cols; ++j)
      result[i][j] = a[i][j] + b[i][j];
  }
  return result;
}

void print(const Matrix& m) {
  int rows = m.size();
  int cols = m[0].size();
  
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j)
      cout << m[i][j] << " ";
    cout << endl;
  }
}

int main (){
  Matrix A = {{6, 4}, {8, 3}};
  Matrix B = {{1, 2, 3}, {4, 5, 6}};
  Matrix C = {{2, 4, 6}, {1, 3, 5}};

  Matrix B_scaled = scalarMultiply(B, 3);
  Matrix C_transposed = transpose(C);
  Matrix product = multiply(B_scaled, C_transposed);
  Matrix D = add(A, product);

  cout << "Matrix D:" << endl;
  printMatrix(D);
  return 0;
}
