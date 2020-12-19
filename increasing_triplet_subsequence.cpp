#include <vector>

#define ll    long long
#define ul    unsigned long long
using std::vector;
using std::string;

class Solution {
public:
    bool increasingTriplet(vector<int> nums) {
      if (nums.size() < 3) return false;
      int a = INT_MAX, b = INT_MAX;
      for (int i = 1; i < nums.size(); ++i) {
        int& c = nums[i-1];
        int& d = nums[i];
        if (c < d) {
          if (c > a || d > b) {
            return true;
          } else {
            a = c;
            b = d;
          }
        }
      }
      return false;
    }
};
