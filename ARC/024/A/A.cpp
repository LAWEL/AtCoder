#include <iostream>
#include <algorithm>

using namespace std;

int cnt[2][41];

int main(){
	for(int i=0;i<2;i++){
		for(int j=0;j<41;j++){
			cnt[i][j] = 0;
		}
	}
	int L, R;
	cin >> L >> R;
	for(int i=0;i<L;i++){
		int in;
		cin >> in;
		cnt[0][in]++;
	}
	for(int i=0;i<R;i++){
		int in;
		cin >> in;
		cnt[1][in]++;
	}	
	int ans = 0;
	for(int i=0;i<41;i++){
		ans += min(cnt[0][i], cnt[1][i]);
	}
	cout << ans << endl;
	return 0;
}
