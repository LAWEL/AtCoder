#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int ans = 0;
    while(N > 0){
        if(N % 10 == 2) ans++;
        N /= 10;
    }
    cout << ans << endl;
}