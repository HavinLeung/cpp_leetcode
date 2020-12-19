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
    ListNode* oddEvenList(ListNode* head) {
      if (head == nullptr || head->next == nullptr) return head;
      ListNode *oddhead = head, *evenhead = head->next;
      ListNode *oddcur = oddhead, *evencur = evenhead;

      while (oddcur->next || evencur->next){
        oddcur->next = evencur->next;
        oddcur = (oddcur->next)? oddcur->next : oddcur;
        evencur->next = oddcur->next;
        evencur = (evencur->next)? evencur->next : evencur;
      }

      oddcur->next = evenhead;
      return oddhead;
    }
};
