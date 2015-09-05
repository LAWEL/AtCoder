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

void add_prime_factor(int n, map<int, int>& fac) {
  for(int i = 2; i * i <= n; ++i) {
    while(n % i ==0) {
      ++fac[i];
      n /= i;
    }
  }
  if(n != 1) {
    ++fac[n];
  }
}

int main() {
  int A, B;
  cin >> A >> B;
  map<int, int> fac;
  for(int i = B + 1; i <= A; ++i) {
    add_prime_factor(i, fac);
  }
  ll ans = 1;
  const ll M = 1000000007LL;
  for(auto p : fac){
    ans = ans * (p.second + 1) % M;
  }
  cout << ans << endl;
}
