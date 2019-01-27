#include <iostream>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;

int main(){
    ll N, P;
    cin >> N >> P;
    if(P == 1){
        cout << 1 << endl;
        return 0;
    }
    map<ll, ll> m;
    for(ll i = 2; i <= (ll)(sqrt(P) + 1); ++i){
        while(P % i == 0 && P > 1){
            P /= i;
            m[i]++;
        }
    }
    if(P != 1){
        m[P] = 1;
    }
    ll ans = 1;
    for(auto it = m.begin(); it != m.end(); ++it){
        ll A = it->first;
        ll B = it->second;
        if(B >= N){
            ll C = B / N;
            for(ll i = 0; i < C; ++i){
                ans *= A;
            }
        }
    }
    cout << ans << endl;
}