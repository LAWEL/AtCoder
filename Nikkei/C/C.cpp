#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i] >> B[i];
    }
    priority_queue<P> p, q;
    for(int i = 0; i < N; ++i){
        p.push(make_pair(A[i], i));
        q.push(make_pair(B[i], i));
    }
    vector<bool> memo(N, false);
    ll sum_a = 0, sum_b = 0;
    for(int i = 0; i < N; ++i){
        P a, b;
        while(true){
            a = p.top();
            if(memo[a.second]){
                p.pop();
                continue;
            }else{
                break;
            }
        }
        while(true){
            b = q.top();
            if(memo[b.second]){
                q.pop();
                continue;
            }else{
                break;
            }
        }
        //cerr << a.first << ", " << b.first << ", ";
        if(i % 2 == 0){
            if(a.first >= b.first){
                memo[a.second] = true;
                sum_a += a.first;
            }else{
                memo[b.second] = true;
                sum_a += A[b.second];
            }
        }else{
            if(b.first >= a.first){
                memo[b.second] = true;
                sum_b += b.first;
            }else{
                memo[a.second] = true;
                sum_b += B[a.second];
            }
        }
        //cerr << sum_a << ", " << sum_b << endl;
    }
    cout << sum_a - sum_b << endl;
}