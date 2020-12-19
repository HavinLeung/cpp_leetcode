#include <vector>
#include <string>
#include <iostream>

#define ll  long long
#define ul  unsigned long long

using std::vector;
using std::string;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      ul n = nums.size();
      ll cumulative = 1;
      vector<int> right = vector(n, nums[n-1]);
      for (ul i = 1; i < n; ++i) {
        ul idx = n - 1 - i;
        right[idx] = right[idx + 1]*nums[idx];
      }
      for (int i = 0; i < n-1; ++i) {
        right[i] = (cumulative * right[i+1]);
        cumulative *= nums[i];
      }
      right[n-1] = cumulative;
      return right;
    }
};