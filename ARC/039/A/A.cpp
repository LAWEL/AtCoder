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

int calc(string a, string b){
  return stol(a) - stol(b);
}

int main() {
  initIOStream();

  string a, b;
  cin >> a >> b;
  int valM = calc(a, b);
  for(size_t i = 0; i < a.size(); ++i){
    string tmp = a;
    tmp[i] = '9';
    valM = max(valM, calc(tmp, b));
  }
  for(size_t i = 0; i < b.size(); ++i){
    string tmp = b;
    tmp[i] = (i == 0 ? '1' : '0');
    valM = max(valM, calc(a, tmp));
  }
  cout << valM << endl;
}
