#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iostream>

#define ll long long
#define ul unsigned ll

using std::vector;
using std::string;

class Solution {
public:
//private:
    enum Cell_state {DEAD=0,ALIVE=1,WAS_DEAD=2,WAS_ALIVE=3,OUT_OF_BOUNDS=-1};
    /**
     * 0 = dead, 1 = alive, 2 = dead->alive, 3 = alive->dead
     */

    static Cell_state get(const vector<vector<int>>& board, int i, int j){
      if (i >= board.size() or j >= board[0].size()) {
        return OUT_OF_BOUNDS;
      }
      return Cell_state(board[i][j]);
    }

    static int numberOfLiveNeighbors(const vector<vector<int>>& board, int i, int j) {
      vector<std::tuple<int, int >> neighbors = {
          {i+1,j+1},{i+1,j},{i+1, j-1},
          {i, j+1},{i, j-1},
          {i-1,j+1},{i-1, j},{i-1,j-1}
      };
      int aliveCount = 0;
      for (auto&[x, y] : neighbors) {
        auto val = get(board,x,y);
        if (val == ALIVE or val == WAS_ALIVE) {
          ++aliveCount;
        }
      }
      return aliveCount;
    }

public:
    /**
     * Rules:
     * 1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
     * 2. Any live cell with two or three live neighbors lives on to the next generation.
     * 3. Any live cell with more than three live neighbors dies, as if by over-population.
     * 4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
     */
    void gameOfLife(vector<vector<int>>& board) {
      if (board.empty() or board[0].empty()) return;

      int n = board.size(), m = board[0].size();
      // first pass
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          auto num_alive_neighbors = numberOfLiveNeighbors(board,i,j);
          if (board[i][j] == DEAD) {
            if (num_alive_neighbors == 3) board[i][j] = WAS_DEAD;
          } else if (board[i][j] == ALIVE) {
            if (num_alive_neighbors < 2) {
              board[i][j] = WAS_ALIVE;
            } else if (num_alive_neighbors > 3) {
              board[i][j] = WAS_ALIVE;
            }
          } else {
            assert(false);
          }
        }
      }
      // second pass
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (board[i][j] == WAS_ALIVE) board[i][j] = DEAD;
          if (board[i][j] == WAS_DEAD) board[i][j] = ALIVE;
        }
      }
    }
};
