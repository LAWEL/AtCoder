#include <iostream>
#include <tuple>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
typedef long long ll;
const ll MAX_N = 1 << 17;
const ll INF = 1LL << 40;

ll n, dat[2 * MAX_N - 1];

void init(ll n_) {
  n = 1;
  while(n < n_) n *= 2;
  rep(i,2*n-1) dat[i] = INF;
}

void update(ll k, ll a) {
  k += n - 1;
  dat[k] = a;
  while(k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

ll query(ll a, ll b, ll k, ll l, ll r) {
  if(r <= a || b <= l) return INF;
  if(a <= l && r <= b) return dat[k];
  else {
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
}

int main() {
  ll N, L;
  cin >> N >> L;
  vector<tuple<ll, ll, ll>> vec;
  rep(i,N) {
    ll l, r, c;
    cin >> l >> r >> c;
    vec.push_back(make_tuple(l, r, c));
  }
  sort(vec.begin(), vec.end());
  init(L+1);
  update(0, 0);
  rep(i,(ll)vec.size()) {
    ll l = get<0>(vec[i]);
    ll r = get<1>(vec[i]);
    ll c = get<2>(vec[i]);
    ll valm = query(l, r+1, 0, 0, n);
    if(dat[r+n-1] > valm + c){
      update(r, valm + c);
    }
  }
  cout << dat[L+n-1] << endl;
  return 0;
}
