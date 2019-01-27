#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> vec;

void dfs(ll x, int a, int b, int c, int d){
    if(a > 0 && b > 0 && c > 0) vec.emplace_back(x);
    if(d > 9) return;
    dfs(x * 10 + 7, a + 1, b, c, d + 1);
    dfs(x * 10 + 5, a, b + 1, c, d + 1);
    dfs(x * 10 + 3, a, b, c + 1, d + 1);
}

int main(){
    dfs(0, 0, 0, 0, 0);
    sort(vec.begin(), vec.end());
    ll n;
    cin >> n;
    auto it = upper_bound(vec.begin(), vec.end(), n);
    cout << (it - vec.begin()) << endl;
}