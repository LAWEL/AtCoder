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
#include <stack>
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

int main() {
  initIOStream();

  int N;
  cin >> N;
  vector<ll> h(N);
  for(int i = 0; i < N; ++i) {
    cin >> h[i];
  }
  vector<int> u(N);
  u[0] = 1;
  for(int i = 1; i < N; ++i) {
    if(h[i-1] < h[i]){
      u[i] = u[i-1] + 1;
    }else{
      u[i] = 1;
    }
  }
  vector<int> d(N);
  d[N - 1] = 1;
  for(int i = N - 2; i >= 0; --i) {
    if(h[i] > h[i+1]){
      d[i] = d[i+1] + 1;
    }else{
      d[i] = 1;
    }
  }
  int ans = 0;
  for(int i = 0; i < N; ++i) {
    ans = max(ans, u[i] + d[i] - 1);
  }
  cout << ans << endl;
}
