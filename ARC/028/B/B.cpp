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
  int N, K, X;
  cin >> N >> K;
  set<pair<int, int> > hoge;
  for(int i = 0; i < N; ++i) {
    cin >> X;
    if(i < K) {
      hoge.insert(make_pair(X, i + 1));
    }
    if(i >= K - 1) {
      if(i >= K) {
        auto piyo = hoge.end();
        piyo--;
        if((*piyo).first > X) {
          hoge.erase(piyo);
          hoge.insert(make_pair(X, i + 1));
        }
      }
      auto fuga = hoge.end();
      fuga--;
      cout << (*fuga).second << endl;
    }
  }
  return 0;

}
