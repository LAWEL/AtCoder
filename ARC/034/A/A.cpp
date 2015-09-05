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

int main() {
  int N;
  cin >> N;
  double ans = 0;
  for(int i = 0; i < N; ++i) {
    double sum = 0;
    for(int j = 0; j < 5; ++j) {
      double x;
      cin >> x;
      if(j == 4) x = x * 110 / 900;
      sum += x;
    }
    ans = max(ans, sum);
  }
  cout << fixed << setprecision(8) << ans << endl;
  return 0;
}
