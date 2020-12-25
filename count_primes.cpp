#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iostream>

#define ll long long
#define ul unsigned ll

using std::vector;

class Solution {
public:
    int countPrimes(int n) {
      // todo - more efficient version
      if (n <= 2) return 0;
      vector<int> primes = {2};
      for (int i = 3; i < n; ++i) {
        bool is_prime = true;
        for (auto& prime : primes) {
          if (i % prime == 0){
            is_prime = false;
            break;
          } else if (prime*prime >= i) break;
        }
        if (is_prime) primes.emplace_back(i);
      }
      return primes.size();
    }
};
