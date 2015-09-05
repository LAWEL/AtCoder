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

int dy[3] = {0, 1, 1};
int dx[3] = {1, 1, 0};
int H, W;
int vis[100][100][2];
char dat[100][100];

int dfs(int y, int x, int t){
  //cout << y << ", " << x << ", " << t << endl;
  if(vis[y][x][t] != -1) return vis[y][x][t];
  int res;
  if(t == 0){
    res = 0;
    for(int i = 0; i < 3; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(!valid(ny, H) || !valid(nx, W) || dat[ny][nx] == '#') continue;
      if(dfs(ny, nx, 1 - t)) res = 1;
    }
  }else{
    res = 1;
    for(int i = 0; i < 3; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(!valid(ny, H) || !valid(nx, W) || dat[ny][nx] == '#') continue;
      if(!dfs(ny, nx, 1 - t)) res = 0;
    }
  }
  vis[y][x][t] = res;
  //cout << y << ", " << x << ", " << t << ", res = "<< res << endl;
  return res;
}

int main() {
  initIOStream();

  memset(vis, -1, sizeof(vis));
  cin >> H >> W;
  for(int i = 0; i < H; ++i) {
    for(int j = 0; j < W; ++j) {
      cin >> dat[i][j];
    }
  }
  cout << (dfs(0, 0, 0) ? "First" : "Second") << endl;
}
