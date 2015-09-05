#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100000;
int n;
vector<int> vec;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int in;
		cin >> in;
		in--;
		vec.push_back(in);
	}

	int ans = 1;
	bool used[N];
	for(int i=0;i<N;i++) used[i] = false;

	int l = 0, r = 0;

	for(;r<n;r++){
		if(used[vec[r]]){
			ans = max(ans, r - l);
			for(;vec[l]!=vec[r];l++){
				used[vec[l]] = false;
			}
			l++;
		}
		used[vec[r]] = true;
	}
	ans = max(ans, r - l);
	cout << ans << endl;
	return 0;
}
