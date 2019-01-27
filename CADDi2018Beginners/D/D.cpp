#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> P;

map<P, bool> memo;

bool func(int e, int o){
    //cout << e << ", " << o << endl;
    P p = make_pair(e, o);
    if(memo.find(p) != memo.end()){
        return memo[p];
    }
    if(e == 0){
        if(o % 2 == 0){
            memo[p] = false;
            return false;
        }else{
            memo[p] = true;
            return true;
        }
    }
    if(o == 0){
        if(e % 2 == 0){
            memo[p] = false;
            return false;
        }else{
            memo[p] = true;
            return true;
        }
    }

    bool res = true;
    if(e > 0){
        res &= func(e - 1, o + 1);
        res &= func(e - 1, o);
    }
    if(o > 0){
        res &= func(e, o - 1);
    }
    memo[p] = !res;
    return !res;
}

int main(){
    int N;
    vector<int> a;
    cin >> N;
    a.resize(N);
    int e = 0, o = 0;
    for(int i = 0; i < N; ++i){
        cin >> a[i];
        if(a[i] % 2 == 0) e++;
        else o++;
    }
    bool ans = func(e, o);
    if(ans) cout << "first" << endl;
    else cout << "second" << endl;
}