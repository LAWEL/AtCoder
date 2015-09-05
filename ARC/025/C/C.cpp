#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long lli;
struct edge { int to, cost; };
typedef pair<int, int> P;

const int INF = 1 << 28;
const int MAX_V = 2500;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + V, INF);
  d[s] = 0;
	que.push(P(0, s));
	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		for(int i=0;i<(int)G[v].size();i++){
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int main(){
	int N, M , R, T;
	cin >> N >> M >> R >> T;
	for(int i=0;i<M;i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		G[a].push_back((edge){b, c});
		G[b].push_back((edge){a, c});
	}
	V = N;
	long long ans = 0;
	for(int i=0;i<V;i++){
		dijkstra(i);
		sort(d, d+V);
		int l = 1, r = 1;
		while(max(l, r) < V && max(d[l], d[r]) < INF){
			long long a = d[l] * R;
			long long b = d[r] * T;
			if(a < b){
				if(l >= r) ans += V - r - 1;
				else ans += V - r;
				l++;
			}else r++;
		}
	}
	cout << ans << endl;
	return 0;
}
