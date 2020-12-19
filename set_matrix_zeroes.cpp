#include <vector>

#define ll    long long
#define ul    unsigned long long
using std::vector;

class Solution {
private:
    enum Corner_val {BOTH, ROW, COL, NONE};
    static Corner_val checkCorner(const vector<vector<int>>& matrix) {
      bool row = false;
      bool col = false;
      int m = matrix.size();
      int n = matrix[0].size();
      for (int i = 0; i < n; ++i)
        if (matrix[0][i] == 0) {row = true;}
      for (int i = 0; i < m; ++i)
        if (matrix[i][0] == 0) {col = true;}
      if (row && col) {
        return BOTH;
      } else if (row) {
        return ROW;
      } else if (col) {
        return COL;
      } else {
        return NONE;
      }
    }

    static void setRow(vector<vector<int>>& matrix, const ul& row, int val = 0){
      for (int & i : matrix[row])
        i = val;
    }
    static void setCol(vector<vector<int>>& matrix, const ul& col, int val = 0){
      for (auto & row : matrix) {
        row[col] = val;
      }
    }

    static void set1stRowAndCol(vector<vector<int>>& matrix, Corner_val c) {
      switch(c){
        case BOTH:
          setRow(matrix, 0);
          setCol(matrix, 0);
          break;
        case ROW:
          setRow(matrix, 0);
          break;
        case COL:
          setCol(matrix, 0);
          break;
        case NONE:
          break;
      }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
      Corner_val corner = checkCorner(matrix);
      int num_rows = matrix.size();
      int num_cols = matrix[0].size();

      for (int i = 1; i < num_rows; ++i) {
        for (int j = 1; j < num_cols; ++j) {
          if (matrix[i][j] == 0){
            matrix[0][j] = 0;
            matrix[i][0] = 0;
          }
        }
      }

      for (int row = 1; row < num_rows; ++row) {
        if (matrix[row][0] == 0) setRow(matrix, row);
      }
      for (int col = 1; col < num_cols; ++col) {
        if (matrix[0][col] == 0) setCol(matrix, col);
      }
      set1stRowAndCol(matrix, corner);
    }
};
