#include <vector>
#include <string>
#include <iostream>

#define ll  long long
#define ul  unsigned long long

using std::vector;
using std::string;

class Solution {
public:
    enum DIR{U,D,L,R};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int y=0, x=0, dy = 0, dx = 1;
      DIR d = R;
      int ymin=0,ymax=matrix.size(), xmin=0, xmax=matrix[0].size();
      vector<int> ans;
      while (ymin < ymax && xmin < xmax) {
        if (y < ymin || y >= ymax || x < xmin || x >= xmax) return ans;
        ans.push_back(matrix[y][x]);
        y += dy;
        x += dx;

        if (y < ymin || y >= ymax || x < xmin || x >= xmax){
          y -= dy;
          x -= dx;
          if (d == R) {
            ymin += 1;
            d = D;
            dy = 1;
            dx = 0;
          } else if (d == D) {
            xmax -= 1;
            d = L;
            dy = 0;
            dx = -1;
          } else if (d == L) {
            ymax -= 1;
            d = U;
            dy = -1;
            dx = 0;
          } else if (d == U) {
            xmin += 1;
            d = R;
            dy = 0;
            dx = 1;
          }
          y += dy;
          x += dx;
        }
      }
      return ans;
    }
};