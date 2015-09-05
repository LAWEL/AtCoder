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

int N;
int t[4];

int main() {
  cin >> N;
  for(int i = 0; i < N; ++i) {
    cin >> t[i];
  }
  int ans = 1000000;
  for(int i = 0; i < (1 << N); ++i) {
    int a = 0, b = 0;
    for(int j = 0; j < N; ++j) {
      if((i >> j) & 1) {
        a += t[j];
      } else {
        b += t[j];
      }
    }
    ans = min(ans, max(a, b));
  }
  cout << ans << endl;
  return 0;
}
