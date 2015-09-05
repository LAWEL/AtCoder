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
  int a, b;
  cin >> a >> b;
  int c = a * 60 + b;
  int d = 18 * 60;
  cout << d - c << endl;
  return 0;
}
