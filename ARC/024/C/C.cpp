#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
	int N, K;
	string S;
	cin >> N >> K >> S;
	vector<int> cnt(26, 0);
	vector<pair<vector<int>, int> > vec;
	for(int i=0;i<S.size();i++){
		cnt[S[i] - 'a']++;
		if(i >= K - 1){
			if(i >= K){
				cnt[S[i-K] - 'a']--;
			}
			vec.push_back(make_pair(cnt, i));
		}
	}
	sort(vec.begin(), vec.end());
	pair<vector<int>, int> p = vec[0];
	bool ans = false;
	for(int i=1;i<vec.size();i++){
		if(p.first == vec[i].first){
			if(vec[i].second - p.second >= K){
				ans = true;
			}
		}else{
			p = vec[i];
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
