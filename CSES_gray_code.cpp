#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <string>
#include <iostream>

#define ll long long
#define ul unsigned ll

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

/**
 *
 */

void printArr(string* arr, int N) {
  for (int i = 0; i < N; ++i) {
    cout << arr[i] << endl;
  }
}

int main() {
  constexpr int maxN = 1 << 16;
  string arr[maxN];
  int n, N;
  cin >> n;
  N = 1 << n;
  arr[0] = "0";
  arr[1] = "1";
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < (1 << i); ++j) {
      // prepend '0'
      arr[j] = "0" + arr[j];
      // "mirror" over
      arr[(1 << (i+1)) - 1 - j] = arr[j];
      arr[(1 << (i+1)) - 1 - j][0] = '1';
    }
  }
  printArr(arr,N);
}