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

int main() {
  string s;
  cin >> s;
  bool ans = true;
  for(int i = 0; i < s.size() / 2; ++i){
    int j = s.size() - i - 1;
    if(s[i] == s[j] || s[i] == '*' || s[j] == '*'){
    }else{
      ans = false;
    }
  }
  cout << (ans ? "YES" : "NO") << endl;
}
