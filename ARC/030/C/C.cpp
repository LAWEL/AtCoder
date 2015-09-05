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


//SCC O(|V| + |E|)
const int MAX_V = 10000;

int V, E, K, V2;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> G2[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];
char C[MAX_V];
string S[MAX_V];
string ans;

void add_edge(int from, int to){
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v){
  used[v] = true;
  for(int i=0;i<G[v].size();i++){
    if(!used[G[v][i]]) dfs(G[v][i]);
  }
  vs.push_back(v);
}

void rdfs(int v, int k){
  used[v] = true;
  cmp[v] = k;
  for(int i=0;i<rG[v].size();i++){
    if(!used[rG[v][i]]) rdfs(rG[v][i], k);
  }
}

int scc(){
  fill(used, used+MAX_V, false);
  vs.clear();
  for(int v=0;v<V;v++){
    if(!used[v]) dfs(v);
  }
  fill(used, used+MAX_V, false);
  int k = 0;
  for(int i=vs.size()-1;i>=0;i--){
    if(!used[vs[i]]) rdfs(vs[i], k++);
  }
  return k;
}

void dfs2(int v, vector<int>& pre) {
  used[v] = true;
  //cout << "v = " << v << ", " << G2[v].size() << endl;
  if(G2[v].size() == 0) {
    string str;
    for(int i = 0, size = pre.size(); i < size; ++i) {
      str += S[pre[i]];
    }
    str += S[v];
    //cout << "str = " << str << endl;
    if(str.size() < K) return;
    string tmp;
    tmp.resize(K);
    int pre2 = -1;
    const int size = str.size();
    for(int i = 0; i < K; ++i) {
      char valm = 'z' + 1;
      int p = -1;
      for(int j = pre2 + 1; j + K - i <= size; ++j) {
        if(str[j] < valm) {
          valm = str[j];
          p = j;
        }
      }
      //cout << p << endl;
      if(p == -1) return;
      pre2 = p;
      tmp[i] = valm;
    }
    //cout << "tmp = "   << tmp << endl;
    ans = min(ans, tmp);
  }
  for(int i = 0, size = G2[v].size(); i < size; ++i) {
    auto vv = G2[v][i];
    if(used[vv]) continue;
    pre.push_back(v);
    dfs2(vv, pre);
    pre.pop_back();
  }
}

int main() {
  cin >> V >> E >> K;
  for(int i = 0; i < V; ++i) {
    cin >> C[i];
  }
  for(int i = 0; i < E; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    rG[b].push_back(a);
  }
  V2 = scc();
  // for(int i = 0; i < V; ++i) {
  //   cmp[i] = V2 - cmp[i] - 1;
  // }
  for(int i = 0; i < V; ++i) {
    S[cmp[i]].push_back(C[i]);
    for(int j = 0, size = G[i].size();j < size; ++j) {
      if(cmp[i] == cmp[G[i][j]]) continue;
      G2[cmp[i]].push_back(cmp[G[i][j]]);
    }
  }
  for(int i = 0; i < V2; ++i) {
    sort(S[i].begin(), S[i].end());
    //cout << "S[" << i << "] = " << S[i] << endl;
    sort(G2[i].begin(), G2[i].end());
    G2[i].erase(unique(G2[i].begin(), G2[i].end()), G2[i].end());
  }
  memset(used, 0, sizeof(used));
  ans.resize(1);
  ans[0] = 'z' + 1;
  vector<int> tmp;
  for(int i = 0; i < V2; ++i) {
    if(!used[i]) {
      dfs2(i, tmp);
    }
  }
  if(ans.size() == 1 && ans[0] == 'z' + 1) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
