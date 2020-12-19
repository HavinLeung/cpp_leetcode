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
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      size_t N = A.size();
      if (N == 0) return 0;
      int num = 0;
      std::unordered_map<int, int> targets;
      targets.reserve(2*A.size()*B.size());
      for (auto& a : A){
        for (auto& b : B) {
          targets[a + b] += 1;
        }
      }

      for (auto& c : C) {
        for (auto& d : D) {
          num += targets[-c-d];
        }
      }

      return num;
    }
};