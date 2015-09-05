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

const int S = 30000;

ll a[S], b[S], N, K;

pair<ll, ll> f(ll x, ll k){
  auto it = upper_bound(b, b + N, k / x + (k % x != 0 ? 1 : 0)) - b;
  //cout << it << endl;
  return make_pair(it, x * b[it-1]);
  if(x * b[0] >= k) return make_pair(0, 0);
  ll l = 0, r = N;
  while(r - l > 1){
    ll m = (l + r) / 2;
    if(x * b[m] < k){
      l = m;
    }else{
      r = m;
    }
  }
  return make_pair(l + 1, x * b[l]);
}

pair<ll, ll> check(ll k){
  //cout << "check(" << k << ")" << endl;
  pair<ll, ll> res = make_pair(0, 0);
  for(ll i = 0; i < N; ++i) {
    auto tmp = f(a[i], k);
    //cout << tmp.first << ", " << tmp.second << endl;
    res.first += tmp.first;
    res.second = max(res.second, tmp.second);
  }
  return res;
}

int main() {
  initIOStream();

  cin >> N >> K;
  for(int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  for(int i = 0; i < N; ++i) {
    cin >> b[i];
  }
  sort(a, a + N);
  sort(b, b + N);
  ll l = 0, r = 1000000000LL * 1000000000LL + 2LL;
  pair<ll, ll> res;
  while(r - l > 1){
    ll m = (l + r) / 2;
    res = check(m);
    //cout << "res = (" << res.first << ", " << res.second << ")" << endl;
    if(res.first == K){
      break;
    }else if(res.first < K){
      l = m + 1;
    }else{
      r = m;
    }
  }
  cout << res.second << endl;
}
