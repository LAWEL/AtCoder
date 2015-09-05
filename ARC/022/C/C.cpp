#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> P;

class S{
public:
	int d, a, b;
	S(int d, int a, int b): d(d), a(a), b(b) {}
	bool operator < (const S& s) const {
		return d < s.d;
	}
};

const int N = 100000;
int n;
vector<int> G[N];
bool vis[N];
S ans = S(0, 0, 0);

S dfs(int p){
	S res = S(0, p, p);
	vis[p] = true;
	vector<S> vec;
	for(int i=0;i<G[p].size();i++){
		if(!vis[G[p][i]]){
			S tmp = dfs(G[p][i]);
			tmp.d++;
			tmp.a = p;
			vec.push_back(tmp);
			res = max(res, tmp);
		}
	}
	if(vec.size() == 1){
		ans = max(ans, vec[0]);
	}else if(vec.size() > 1){
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		ans = max(ans, S(vec[0].d + vec[1].d, vec[0].b, vec[1].b));
	}
	vis[p] = false;
	return res;
}

int main(){
	for(int i=0;i<N;i++){
		vis[i] = false;
	}		
	cin >> n;
	for(int i=0;i<n-1;i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0);
	cout << ans.a + 1<< ' ' << ans.b + 1<< endl;
	return 0;
}
