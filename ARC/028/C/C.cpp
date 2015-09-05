#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <complex>
#include <cassert>
#include <cmath>
#include <tuple>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <climits>
#include <string>
#include <memory>
#include <array>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

const int MAX = 1000000;

vector<int> G[MAX];
int N;
int cnt[MAX];
int ans[MAX];
bool vis[MAX];

void dfs(int p) {
  vis[p] = true;
  ans[p] = 0;
  cnt[p] = 1;
  for(size_t i = 0; i < G[p].size(); ++i) {
    if(vis[G[p][i]]) continue;
    dfs(G[p][i]);
    cnt[p] += cnt[G[p][i]];
    ans[p] = max(ans[p], cnt[G[p][i]]);
  }
  ans[p] = max(ans[p], N - cnt[p]);
}

int main() {
  cin >> N;
  for(int i = 0; i < N - 1; ++i) {
    int p;
    cin >> p;
    G[i+1].push_back(p);
    G[p].push_back(i+1);
  }
  fill(vis, vis+MAX, false);
  dfs(0);

  for(int i = 0;i < N; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}
