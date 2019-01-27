#include <iostream>

using namespace std;

int main(){
    long long N, H, W;
    cin >> N >> H >> W;
    long long ans = 0;
    for(int i = 0; i < N; ++i){
        long long A, B;
        cin >> A >> B;
        if(A >= H && B >= W) ans++;
    }
    cout << ans << endl;
}