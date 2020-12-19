#include <vector>
#include <stack>

#define ll    long long
#define ul    unsigned long long

using std::vector;
using std::stack;

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
    void rec(TreeNode* root, vector<int>& res) {
      if (root) {
        rec(root->left, res);
        res.emplace_back(root->val);
        rec(root->right, res);
      }
    }

    void iter(TreeNode* root, vector<int>& res){
      if (!root) return;
      stack<std::pair<TreeNode*, bool>> stack;
      stack.push(std::make_pair(root, true));
      while(!stack.empty()) {
        auto [top, b] = stack.top();
        stack.pop();
        if (top->left && b) {
          stack.push(std::make_pair(top, false));
          stack.push(std::make_pair(top->left, true));
        } else {
          res.emplace_back(top->val);
          if(top->right) stack.push(std::make_pair(top->right, true));
        }
      }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      iter(root, res);
      return res;
    }
};
