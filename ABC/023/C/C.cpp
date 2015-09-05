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

const int MAX = 100000;
int a[2][MAX];
set<pair<int, int> > mem;

int main() {
  initIOStream();

  int R, C, K;
  cin >> R >> C >> K;
  int N;
  cin >> N;
  memset(a, 0, sizeof(a));
  for(int i = 0; i < N; ++i) {
    int r, c;
    cin >> r >> c;
    ++a[0][r-1];
    ++a[1][c-1];
    mem.insert(make_pair(r, c));
  }
  int ans = 0;
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < MAX; ++j) {
      if(
    }
  }

}
