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

typedef long long ll;

const ll MAX_N = 2000;
const ll MOD = 1000000007;

int a[MAX_N];

int dp[MAX_N + 1][MAX_N + 1];

void solve(int n, int m) {
  memset(dp, 0, sizeof(dp));
  for(int i = 0; i <= n; ++i) {
    dp[i][0] = 1;
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 1; j <= m; ++j) {
      int tmp = j - 1 - a[i];
      if(tmp >= 0) {
        dp[i + 1][j] = (static_cast<ll>(dp[i + 1][j - 1]) + dp[i][j] - dp[i][tmp] + MOD) % MOD;
      } else {
        dp[i + 1][j] = (static_cast<ll>(dp[i + 1][j - 1]) + dp[i][j]) % MOD;
      }
    }
  }
  printf("%d\n", dp[n][m]);
}

int main() {
  int n, m, Q;
  scanf("%d%d%d", &n, &m, &Q);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < Q; ++i) {
    int k, x;
    scanf("%d%d", &k, &x);
    int tmp = a[k-1];
    a[k-1] = 0;
    solve(n, m - x);
    a[k-1] = tmp;
  }
  return 0;
}
