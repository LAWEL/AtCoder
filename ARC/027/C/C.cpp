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

int main() {
  int X, Y;
  int N;
  array<int, 300> t, h;
  cin >> X >> Y >> N;
  for(int i=0;i<N;i++){
    cin >> t[i] >> h[i];
  }
  
  int dp[2][301][601];
  for(int i=0;i<301;i++){
    for(int j=0;j<601;j++){
      dp[0][i][j] = -1;
    }
  }
  dp[0][0][0] = 0;
  for(int i=0;i<N;i++){
    int n = i % 2;
    int nn = (i+1) % 2;
    for(int j=0;j<301;j++){
      for(int k=0;k<601;k++){
        dp[nn][j][k] = dp[n][j][k];
      }
    }

    for(int k=0;k+t[i]<=X+Y;k++){
      for(int j=0;j+1<=X;j++){
        if(dp[n][j][k] == -1) continue;
        dp[nn][j + 1][k + t[i]] = max(dp[nn][j+1][k+t[i]], dp[n][j][k] + h[i]);
      }
    }
  }
  long long ans = 0;
  for(int i=0;i<301;i++){
    for(int j=0;j<601;j++){
      ans = max(ans, (long long)dp[N%2][i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
