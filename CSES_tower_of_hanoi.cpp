#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
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

void solve(int n, std::tuple<int,int,int> lol, vector<std::tuple<int,int>>& moves) {
  auto [src, aux, dst] = lol;
  if (n == 1) {
    moves.emplace_back(src,dst);
  } else {
    solve(n-1, {src, dst, aux},moves);
    moves.emplace_back(src,dst);
    solve(n-1, {aux,src,dst},moves);
  }
}

int main() {
  int n;
  cin >> n;
  vector<std::tuple<int,int>> moves;
  solve(n,{1,2,3}, moves);
  cout << moves.size() << endl;;
  for (auto[x,y] : moves) {
    cout << x << ' ' << y << endl;
  }
}

