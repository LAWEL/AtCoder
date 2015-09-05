#include <algorithm>
#include <array>
#include <bitset>
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

vector<ull> divisor(ull n) {
  vector<ull> res;
  res.reserve(sqrt(n));
  for(ull i = 1; i * i <= n; ++i){
    if(n % i == 0){
      res.push_back(i);
      if(i != n / i) res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for(ll i = 2; i * i <= n; ++i) {
    while(n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if(n != 1) ++res[n];
  return res;
}

const ll M = 1000000007LL;

ll calc(ll N, ll K){
  const auto fac = prime_factor(K);
  ll res = 0;
  const ll size = fac.size();
  for(int i = 0; i < (1 << size); ++i){
    int cnt = 0;
    ll r = 1;
    auto it = fac.begin();
    for(int j = 0; j < size; ++j, ++it){
      if(i & (1 << j)){
        ++cnt;
        r *= it->first;
      }
    }
    const auto t = N / r;
    const auto v = t * (t + 1) * r / 2;
    if(cnt % 2 == 0){
      res += v;
    }else{
      res -= v;
    }
  }
  return (res + M) % M;
}

int main() {
  initIOStream();

  ll N, K, ans = 0;
  cin >> N >> K;

  const auto div = divisor(K);
  for(auto x : div) {
    ans = (ans + calc(N / x, K / x) * K) % M;
  }
  cout << ans << endl;
}
