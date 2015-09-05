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

const int N = 10;
char dat[N][N];
bool vis[N][N];
int rem;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
  vis[y][x] = true;
  rem--;
  for(int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(min(ny, nx) < 0 || max(ny, nx) >= N) continue;
    if(dat[ny][nx] != 'o' || vis[ny][nx]) continue;
    dfs(ny, nx);
  }
}

int main() {
  int cnt = 0;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      cin >> dat[i][j];
      if(dat[i][j] == 'o') cnt++;
    }
  }
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if(dat[i][j] == 'x') {
        dat[i][j] = 'o';
        memset(vis, 0, sizeof(vis));
        rem = cnt + 1;
        dfs(i, j);
        if(rem == 0) {
          cout << "YES" << endl;
          return 0;
        }
        dat[i][j] = 'x';
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
