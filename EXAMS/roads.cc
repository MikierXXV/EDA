#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int, int> ArcP;
typedef vector<vector<ArcP>> Graf;

const int infinite = INT_MAX;

int cost_min(const Graf& g, int a, int b, vector<int>& w){
	int n = g.size();
	vector<bool> vis(n, false);
	vector<int> dist(n, infinite);
	priority_queue<ArcP, vector<ArcP>, greater<ArcP>> pq;

	dist[a] = 0;
	pq.push({0,a});

	while(not pq.empty()){
		int c = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(not vis[u]){
			vis[u] = true;
			if(u == b) return dist[u];
			for (ArcP p: g[u]){
				int v = p.second;
				int cost_uv = p.first;
				if (v != b) cost_uv += w[v];
				if (dist[v] > dist[u] + cost_uv){
					dist[v] = dist[u] + cost_uv;
					pq.push({dist[v], v});
				}
			}
		}
	}
	return infinite;
}

int main(){
	int n, m;
	cin >> n >> m;

	vector<int> w(n);
	for (int i = 0; i < n; ++i) cin >> w[i];

	Graf g(n);
	
	for(int i = 0; i < m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({c, v});
		g[v].push_back({c, u});
	}
	int a, b;
	while(cin >> a >> b){
		int coste = cost_min(g, a, b, w);
		cout << "c(" << a << "," << b << ") = ";
		if (coste == infinite) cout << "+oo" << endl;
		else cout << coste << endl;
	}

}