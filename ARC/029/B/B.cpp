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

const double EPS = 1e-6;

bool check(int A, int B, int C, int D) {
  if(A > B) swap(A, B);
  if(C > D) swap(C, D);
  //cout << A << B << C << D << endl;
  if(A >= C && B >= D) return true;
  double a = A;
  double b = B;
  double h = a * b / sqrt(a * a + b * b);
  double tan1 = h / sqrt(a * a - h * h);
  double tan2 = h / sqrt(b * b - h * h);
  double x = (sqrt(a * a + b * b) - D) / 2.0;
  if(x < EPS) return false;
  return x * tan1 + x * tan2 + EPS > C;
}

int main() {
  int A, B;
  int N;
  cin >> A >> B;
  cin >> N;
  for(int i = 0; i < N; ++i) {
    int C, D;
    cin >> C >> D;
    cout << (check(C, D, A, B) ? "YES" : "NO") << endl;
  }
  return 0;
}
