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
		if(col[0] != col[N-1]){
			int valM = 1;
			int c = 1;
			for(int i=1;i<N;i++,c++){
				if(col[i] != col[i-1]){
					valM = max(valM, c);
					c = 0;
				}
			}
			valM = max(valM, c);
			cout << (valM+1)/2 << endl;
		}else{
			int s = 0;
			for(int i=1;i<N;i++){
				if(col[i] != col[i-1]){
					s = i;
					break;
				}
			}
			int valM = 1;
			int c = 1;
			for(int i=1;i<N;i++,c++){
				int p = (s + i) % N;
				if(col[p] != col[(p-1+N)%N]){
					valM = max(valM, c);
					c = 0;
				}
			}
			valM = max(valM, c);
			cout << (valM+1)/2 << endl;
		}
	}
	return 0;
}
