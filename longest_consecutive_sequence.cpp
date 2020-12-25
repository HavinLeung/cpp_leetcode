#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

#define ll long long
#define ul unsigned ll

using std::vector;
using std::string;
using std::cout;
using std::endl;


class Solution {
    template<typename T>
    static inline bool contains(const std::unordered_set<T>& set, const T& val) {
      if (set.count(val) == 0) return false;
      return true;
    }

    /**
     * first solution: memoization, O(N) total time and space
     * */
    static int get(std::unordered_map<int,int>& L, const std::unordered_set<int>& S, int key) {
      if (!contains(S,key)) {
        return 0;
      } else if (L.count(key) != 0) {
        return L[key];
      } else {
        L[key] = 1+get(L,S,key+1);
        return L[key];
      }
    }
    /**
     * second solution: clever way to walk only when key is lowest element in its
     * contiguous subsequence. O(N) total time, O(1) total space
     * */
    static int get(const std::unordered_set<int>& S, int key) {
      if (contains(S, key-1)) {
        return 2;
      }
      int C = key+1;
      while (contains(S, C)) {
        C++;  // heh
      }
      return C-key;
    }
public:
    int longestConsecutive(vector<int>& nums) {
      if (nums.size() <= 1) return nums.size();
      const auto S = std::unordered_set<int>(nums.begin(), nums.end());
      std::unordered_map<int,int> L;
      int largest = 1;
      for (auto& x : S) {
        largest = std::max(largest, get(S,x));
      }
      return largest;
    }
};
