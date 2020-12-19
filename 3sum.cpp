//
// Created by Havin Leung on 2020-11-19.
//
#include <vector>
#include <algorithm>
#define ll    long long
#define ul    unsigned long long

using std::vector;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> sol;
      if (nums.size() < 3) return sol;
      std::sort(nums.begin(), nums.end());
      for (ul i = 0; i < nums.size(); ++i) {
        ul m = i+1;
        ul r = nums.size()-1;
        while (m < r){
          int s = nums[i] + nums[m] + nums[r];
          if (s < 0){
            m+=1;
          } else if (s > 0) {
            r-=1;
          } else {
            sol.emplace_back(vector{nums[i] , nums[m] , nums[r]});
            ++m;
            --r;
            while (m < r && nums[m] == nums[m-1]) ++m;
            while (m < r && nums[r] == nums[r+1]) --r;
          }
        }

        while (i < nums.size()-1 && nums[i] == nums[i+1]) ++i;
      }

      return sol;
    }
};
