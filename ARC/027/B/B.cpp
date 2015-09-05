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

typedef long long ll;

int N;
string a, b;

void func() {
 bool fin = false;
  while(!fin) {
    fin = true;
    for(int i=0;i<N;++i){
      if(isdigit(a[i]) && !isdigit(b[i])) {
        for(int j=0;j<N;j++){
          if(i == j) continue; 
          if(a[j] == b[i]){
            a[j] = a[i];
          }
          if(b[j] == b[i]){
            b[j] = a[i];
          }
        }
        b[i] = a[i];
        fin = false;
      } else if(!isdigit(a[i]) && isdigit(b[i])) {
        for(int j=0;j<N;j++){
          if(i == j) continue;
          if(a[j] == a[i]){
            a[j] = b[i];
          }
          if(b[j] == a[i]){
            b[j] = b[i];
          }
        }
        a[i] = b[i];
        fin = false;
      }
    }
  }
}

int main() {
  cin >> N >> a >> b;
  func();
  long long ans = 1;
  for(int i=0;i<N;i++){
    if(isdigit(a[i])) {
    }else{
      ans *= (i == 0 ? 9 : 10);
      for(int j=0;j<N;j++){
        if(i == j) continue;
        if(a[j] == a[i] || a[j] == b[i]) {
          a[j] = '9';
        }
        if(b[j] == a[i] || b[j] == b[i]) {
          b[j] = '9';
        }
      }
      a[i] = '9';
      b[i] = '9';
      func();
    }
  }
  cout << ans << endl;
  return 0;
}
