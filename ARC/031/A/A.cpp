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

int main() {
  string str;
  cin >> str;
  int size = str.size();
  bool f = true;
  for(int i = 0, j = size - 1; i < j; i++, j--){
    if(str[i] != str[j]) f = false;
  }
  cout << (f ? "YES" : "NO") << endl;
  return 0;
}
