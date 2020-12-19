#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iostream>

#define ll long long
#define ul unsigned ll

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
private:
    static void recurse(TreeNode* node, int target, std::unordered_map<int,int>& prefix_sums, int cur_sum, int& count){
      if (node == nullptr) return;
      cur_sum += node->val;
      int desired = cur_sum - target;
      if (desired == 0) count += 1;
      count += prefix_sums[desired];
      prefix_sums[cur_sum]++;
      recurse(node->left, target, prefix_sums, cur_sum, count);
      recurse(node->right, target, prefix_sums, cur_sum, count);
      prefix_sums[cur_sum]--;
    }
public:
    int pathSum(TreeNode* root, int sum) {
      int count = 0;
      std::unordered_map<int,int> prefix_sums;
      recurse(root, sum, prefix_sums, 0, count);
      return count;
    }
};
