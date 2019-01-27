#include <iostream>

using namespace std;

bool f(int x){
    return x == 3 || x == 5 || x == 7;
}

int main(){
    int x;
    cin >> x;
    cout << (f(x) ? "YES" : "NO") << endl;
}