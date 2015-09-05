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

int main() {
  ll N;
  cin >> N;
  vector<ll> T(N);
  for(int i = 0; i < T.size(); ++i){
    cin >> T[i];
  }
  sort(T.begin(), T.end());
  ll ans1 = 0;
  ll sum = 0;
  for(int i = 0, size = T.size(); i < size; ++i){
    sum += T[i];
    ans1 += sum;
  }
  ll cnt = 1;
  ll ans2 = 1;
  ll prev = -1;
  const ll M = 1000000007LL;
  for(int i = 0, size = T.size(); i <= size; ++i){
    ans2 = (ans2 * cnt++ % M);
    if(prev != T[i]){
      cnt = 1;
    }
    if(i == size) break;
    prev = T[i];
  }
  cout << ans1 << endl;
  cout << ans2 << endl;
}
