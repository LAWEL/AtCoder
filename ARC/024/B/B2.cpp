#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N;
	int col[100000];
	cin >> N;
	int cnt[2] = {0, 0};
	for(int i=0;i<N;i++){
		cin >> col[i];
		cnt[col[i]]++;
	}
	if(cnt[0] == 0 || cnt[1] == 0){
		cout << -1 << endl;
	}else{
		int ans = 1;
		while(1){
			int next[100000];
			for(int i=0;i<N;i++){
				int j = (i - 1 + N) % N;
				int k = (i + 1) % N;
				if(col[j] == col[i] && col[i] == col[k]){
					next[i] = 1 - col[i];
				}else{
					next[i] = col[i];
				}
			}
			bool f = true;
			for(int i=0;i<N;i++){
				if(col[i] != next[i]){
					f = false;
				}
				col[i] = next[i];
			}
			if(f){
				break;
			}
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
