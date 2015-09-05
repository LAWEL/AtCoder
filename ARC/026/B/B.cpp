#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

typedef long long lli;

int main(){
  lli sum = 0, n;
  cin >> n;
  for(lli i=1;i*i<=n;i++){
    if(n % i == 0){
      if(i != n) sum += i;
      if(i * i != n && i != 1){
        sum += n / i;
      }
    }
  }
  if(sum == n){
    cout << "Perfect" << endl;
  }else if(sum < n){
    cout << "Deficient" << endl;
  }else{
    cout << "Abundant" << endl;
  }
  return 0;
}
