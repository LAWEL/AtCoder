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

typedef long long ll;
typedef unsigned long long ull;

inline bool valid(const int x, const int r) { return 0 <= x && x < r; }

void initIOStream() {
  ios::sync_with_stdio(false); // stdinなどと同期しない
  cin.tie(0); // cinの前にflushしない
  cout.setf(ios::fixed);
  cout.precision(10); // 四捨五入して指定桁数表示
}

vector<int> G[100];
bool vis[100];

bool dfs(int p, int pre){
  bool res = true;
  vis[p] = true;
  for(int i = 0; i < G[p].size(); ++i) {
    int v = G[p][i];
    if(v == pre) continue;
    if(vis[v]) res = false;
    if(!vis[v]){
      if(!dfs(v, p)) res = false;
    }
  }
  return res;
}

int main() {
  initIOStream();

  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  memset(vis, 0, sizeof(vis));
  int ans = 0;
  for(int i = 0; i < N; ++i) {
    if(!vis[i]){
      ans += dfs(i, -1);
    }
  }
  cout << ans << endl;
}
