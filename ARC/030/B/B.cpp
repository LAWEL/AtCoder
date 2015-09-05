#include <algorithm>
#include <array>
#include <complex>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

void dfs(int pos, vector<bool>& vis, vector<int>& pre, vector<bool>& used, vector<bool> h, vector<vector<int> >& vec, map<pair<int, int>, int>& hoge) {
  vis.at(pos) = true;
  if(h.at(pos)) {
    for(int i = 0, size = pre.size(); i < size; ++i) {
      used.at(pre[i]) = true;
    }
  }
  for(int i = 0, size = vec[pos].size(); i < size; ++i) {
    auto next = vec[pos][i];
    if(vis.at(next)) continue;
    auto tmp = make_pair(pos, next);
    if(tmp.first > tmp.second) swap(tmp.first, tmp.second);
    pre.push_back(hoge[tmp]);
    dfs(next, vis, pre, used, h, vec, hoge);
    pre.pop_back();
  }
}

int main() {
  int n, x;
  cin >> n >> x;
  --x;
  vector<bool> h(n);
  for(int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    h.at(i) = a;
  }
  map<pair<int, int>, int> hoge;
  vector<vector<int> > vec(n, vector<int>(0));
  for(int i = 0; i < n - 1; ++i){
    int a, b;
    cin >> a >> b;
    --a; --b;
    vec[a].push_back(b);
    vec[b].push_back(a);
    if(a > b) swap(a, b);
    hoge[make_pair(a, b)] = i;
  }
  vector<bool> used(n, false);
  vector<int> pre;
  vector<bool> vis(n, false);
  dfs(x, vis, pre, used, h, vec, hoge);
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    if(used.at(i)) ans++;
  }
  cout << ans * 2 << endl;
  return 0;
}
