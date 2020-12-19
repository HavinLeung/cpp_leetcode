#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

#define ll    long long
#define ul    unsigned long long
using std::vector;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if (s.length() < 2) return s.length();
      std::map<char, int> lastSeen;
      int curmax = 0;
      int lastRepeat = -1;
      for (int i = 0; i < s.length(); ++i) {
        char curChar = s[i];
        if (lastSeen.count(curChar) == 1){
          lastRepeat = std::max(lastRepeat, lastSeen[curChar]);
        }
        curmax = std::max(curmax, i - lastRepeat);
        lastSeen[curChar] = i;
      }
      return curmax;
    }
};

