#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <list>
#include <string>
#include <iostream>

#define ll long long
#define ull unsigned ll

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

/**
 *
 */


void solve(ull index) {
  ull num_digits = 1;
  ull num_numbers = 9;
  ull starting_num = 0;
  while (index > (num_numbers * num_digits)) {
    index -= (num_numbers * num_digits);
    starting_num += num_numbers;
    num_numbers *= 10;
    num_digits += 1;
  }
  // TIL about long doubles.. some of these test queries are ridiculously huge lol
  ull to_add = std::ceil((long double) index / (long double) num_digits);
  ull idx = ((index % num_digits) + num_digits - 1) % num_digits;
  string num = std::to_string(starting_num + to_add);
//  assert(num_digits == num.size());
  cout << num[idx] << endl;
}

int main() {
  ull q, k;
  cin >> q;
  for (ull i = 0; i < q; ++i) {
    cin >> k;
    solve(k);
  }
}
