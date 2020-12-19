#include <algorithm>

#define ll    long long
#define ul    unsigned long long

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      auto ret = new ListNode();
      auto cur = ret;
      int carry = 0;

      while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int v1 = (l1 == nullptr)? 0 : l1->val;
        int v2 = (l2 == nullptr)? 0 : l2->val;
        int val = v1 + v2 + carry;
        if (val >= 10) {
          val %= 10;
          carry = 1;
        } else {
          carry = 0;
        }
        auto next = new ListNode(val);
        cur->next = next;
        cur = cur->next;

        l1 = (l1 == nullptr)? l1 : l1->next;
        l2 = (l2 == nullptr)? l2 : l2->next;
      }
      auto r = ret->next;
      delete ret;
      return r;
    }
};
