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
  int N, A, B;
  cin >> N >> A >> B;
  for(int i=0;;i++){
    N -= (i % 2 == 0 ? A : B);
    if(N <= 0) {
      cout << (i % 2 == 0 ?  "Ant" : "Bug") << endl;
      break;
    }
  }
  return 0;
}
