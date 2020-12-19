#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

#define ll    long long
#define ul    unsigned long long
using std::vector;
using std::string;

class Solution {
private:
    static string count(const string& str){
      // making a custom hash function would probably be ideal but I'm lazy
      int counter[26] = {};
      for (const char& c : str) {
        int idx = c - 'a';
        counter[idx] += 1;
      }
      string ret = "";
      for (const int& i : counter) ret.append(std::to_string(i)).append(",");
      return ret;
    }

    static string sort(string str){
      std::sort(str.begin(), str.end());
      return str;
    }
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
      std::map<string, vector<string>> anagrams;
      for (const auto& str : strs){
        string canon = sort(str);
        anagrams[canon].emplace_back(str);
      }
      vector<vector<string>> ret;
      for (const auto& [canon, vals] : anagrams) ret.emplace_back(vals);
      return ret;
    }
};
