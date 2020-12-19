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
    int firstMissingPositive(vector<int>& nums) {
      ll n = nums.size();
      for (ll i = 0; i < n; ++i) {
        if (nums[i]!=i+1) {
          ll index_to_replace = nums[i];
          index_to_replace--;
          while(index_to_replace >= 0 and index_to_replace < n){
            ll temp = nums[index_to_replace];
            if (temp == index_to_replace + 1) break;
            nums[index_to_replace] = index_to_replace + 1;
            index_to_replace = temp-1;
          }
        }
      }

      for (ll i = 0; i < n; ++i) {
        if (nums[i] != i+1) return i+1;
      }
      return n+1;
    }
};
