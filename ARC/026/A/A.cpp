#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(n, 5) * b + (n - min(n, 5)) * a << endl;
  return 0;
}
