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

ll calc(ll x){
  ll res = 0;
  while(x != 0){
    res += x % 10;
    x /= 10;
  }
  return res;
}

int main() {
  ll N;
  cin >> N;
  ll s = max(N - (9*18), 0LL);
  vector<ll> ans;
  for(ll i = s; i <= N; ++i) {
    if(i + calc(i) == N) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for(auto x : ans){
    cout << x << endl;
  }
}
