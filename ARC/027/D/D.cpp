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

const int M = 1000000007;

array<int, 300000> h;
int dp[300000][10];

int main() {
  int N;
  int D;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> h[i];
  }
  fill(dp[0], dp[300000], 0);
  dp[0][0] = 1;
  for(int i=0;i<N;i++){
    long long r = 1;
    for(int j=0;j<10;j++){
      if(dp[i][j] == 0) continue;
      r = (r + dp[i][j]) % M;
    }
    for(int j=1;j<=h[i];j++){
      dp[i+j][j-1] = r;
    }
  }
  cin >> D;
  for(int i=0;i<D;i++){
    int s, t;
    cin >> s >> t;
  }
  return 0;
}
