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

char g[10][10];
bool vis[10][10];
ll sy, sx, H, W, T;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

typedef ll Key;
typedef ll Val;

const ll MAX_V = 100000;
const Key INF = (1LL << 40);

struct edge { Key to; Val cost; };

ll V;
//array<vector<edge>, MAX_V> G;
vector<Val> dist;

bool dijkstra(ll d){
  V = H * W;
  dist.resize(V);
  typedef pair<Key, Val> P;
  priority_queue<P, vector<P>, greater<P> > que;
  fill(dist.begin(), dist.end(), INF);
  dist[sy * W + sx] = 0;
  que.push(P(0, sy * W + sx));

  while(!que.empty()){
    const auto p = que.top(); que.pop();
    const auto v = p.second;
    if(g[v / W][v % W] == 'G') return true;
    if(dist[v] < p.first) continue;
    if(p.first >= T) continue;
    for(ll i = 0; i < 4; ++i) {
      ll ny = v / W + dy[i];
      ll nx = v % W + dx[i];
      if(!valid(ny, H) || !valid(nx, W)) continue;
      auto nv = make_pair(p.first + (g[ny][nx] == '#' ? d : 1), ny * W + nx);
      if(dist[nv.second] < nv.first) continue;
      dist[nv.second] = nv.first;
      que.push(nv);
    }
  }
  return false;
}

int main() {
  initIOStream();

  cin >> H >> W >> T;
  for(ll i = 0; i < H; ++i) {
    for(ll j = 0; j < W; ++j) {
      cin >> g[i][j];
      if(g[i][j] == 'S'){
        sy = i;
        sx = j;
      }
    }
  }

  ll l = 1, r = 1000000001LL;
  while(r - l > 1){
    ll m = (l + r) / 2;
    if(dijkstra(m)){
      l = m;
    }else{
      r = m;
    }
  }
  cout << l << endl;
}
