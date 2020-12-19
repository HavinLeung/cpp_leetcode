#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iostream>

#define ll long long
#define ul unsigned ll

using std::vector;
using std::string;

class Solution {
private:
    static ul area(size_t l, size_t r, const vector<int>& height) {
      return (r - l) * std::min(height[l], height[r]);
    }
public:
    int maxArea(vector<int>& height) {
      size_t l = 0, r = height.size() - 1;
      ul best_area = area(l, r, height);
      while (l < r) {
        if (height[l] <= height[r])
          l += 1;
        else
          r -= 1;

        ul cur_area = area(l,r,height);
        if (cur_area > best_area) {
          best_area = cur_area;
        }
      }
      return best_area;
    }
};