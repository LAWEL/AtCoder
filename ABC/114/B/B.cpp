#include <iostream>
#include <string>

using namespace std;



int main(){
    string s;
    cin >> s;
    int i = 2;
    int ans = 1000;
    for(; i < s.size(); ++i){
        int x = 0;
        x += (s[i-2] - '0') * 100;
        x += (s[i-1] - '0') * 10;
        x += (s[i-0] - '0') * 1;
        ans = min(ans, abs(753 - x));
    }
    cout << ans << endl;
}