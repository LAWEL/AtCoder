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

void print(vector<int>& vec) {
  for(auto e : vec) {
    cout << " " << e;
  }
  cout << endl;
}

long long mergecount(vector<int> &a) {
  long long count = 0;
  long long n = a.size();
  if (n > 1) {
    vector<int> b(a.begin(), a.begin() + n/2);
    vector<int> c(a.begin() + n/2, a.end());
    count += mergecount(b);
    count += mergecount(c);
    for (long long i = 0, j = 0, k = 0; i < n; ++i)
      if (k == (long long)c.size())       a[i] = b[j++];
      else if (j == (long long)b.size())  a[i] = c[k++];
      else if (b[j] <= c[k])   a[i] = b[j++];
      else                   { a[i] = c[k++]; count += n/2 - j; }
  }
  return count;
}

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  int idx;
  int valM = -1;
  for(int i = 0; i < N; ++i) {
    cin >> vec[i];
    if(valM < vec[i]) {
      idx = i;
      valM = vec[i];
    }
  }
  vector<int> vec2(N-1);
  int size = 0;
  vector<long long> dist(N);
  for(int i = 0; i < N; ++i) {
    dist[i] = abs(i - idx);
    //cout << dist[i] << " ";
    if(i == idx) continue;
    vec2[size++] = vec[i];
  }
  //cout << endl;
  auto begin = vec2.begin();
  auto end = vec2.end();
  long long ans = 10000000000000LL;
  for(auto it = vec2.begin();; ++it) {
    vector<int> a(begin, it);
    vector<int> b(it, end);
    reverse(b.begin(), b.end());
     // cout << "a =";
     // print(a);
     // cout << "b =";
     // print(b);
     //cout << "===== " << mergecount(a) << " " << mergecount(b) << " " << dist[it - begin] << endl;
    ans = min(ans, mergecount(a) + mergecount(b) + dist[it - begin]);
    //cout << "ans = " << ans << endl;
    if(it == end) break;
  }
  cout << ans << endl;
  return 0;
}
