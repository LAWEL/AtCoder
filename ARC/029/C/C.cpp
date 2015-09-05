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

typedef pair<long long, long long> P;

long long N, M;
long long C[100000];

struct edge { long long u, v, cost; };

bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

edge es[300000];
long long V, E;

namespace unionfind {

const long long MAX_N = 300000;

long long par[MAX_N];
long long rank[MAX_N];

void init(long long n){
  for(long long i=0;i<n;i++){
    par[i] = i;
    rank[i] = 0;
  }
}

long long find(long long x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(long long x, long long y){
  x = find(x);
  y = find(y);
  if(x == y) return;

  if(rank[x] < rank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rank[x] == rank[y]) rank[x]++;
  }
}

bool same(long long x, long long y){
  return find(x) == find(y);
}

}


long long kruskal() {
  sort(es, es + E, comp);
  unionfind::init(V);
  long long res = 0;
  for(long long i = 0; i < E; ++i) {
    edge e = es[i];
    if(!unionfind::same(e.u, e.v)) {
      unionfind::unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

int main() {
 cin >> N >> M;
  for(long long i = 0; i < N; ++i) {
    cin >> C[i];
    es[i].u = 0;
    es[i].v = i + 1;
    es[i].cost = C[i];
  }
  for(long long i = 0; i < M; ++i) {
    long long a, b, r;
    cin >> a >> b >> r;
    es[i+N].u = a;
    es[i+N].v = b;
    es[i+N].cost = r;
  }
  V = N + 1;
  E = M+N;
  cout << kruskal() << endl;
  return 0;
}
