#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;



typedef	pair<int, int> ArcP; //coste, adyacente vertice
typedef vector<vector<ArcP>> Graf;

const int infinit = INT_MAX;

int coste_minimo(const Graf& g, int a, int b, const vector<int>& w){
	int n = g.size();
	vector<bool> vis(n, false);
	vector<int> dist(n, infinit);
	priority_queue<ArcP, vector<ArcP>, greater<ArcP>> pq;

	dist[a] = 0;
	pq.push({0,a});

	while(not pq.empty()){
		ArcP u = pq.top();
		pq.pop();
		if (not vis[u.second]){
			vis[u.second] = true;
			if (u.second == b) return dist[b];
			else{
				for(ArcP v : g[u.second]){
					int coste = v.first;
					if (v.second != b) coste += w[v.second];
					if (dist[v.second] > dist[u.second] + coste){
						dist[v.second] = dist[u.second] + coste;
						pq.push({dist[v.second], v.second});
					}
				}
			}
		}
	}
	return infinit;
}


int main(){
	int n, m;
	cin >> n >> m;
	vector<int> w(n);
	for (int i = 0; i < n; ++i) cin >> w[i];
	Graf g(n);
	int u, v, c;
	for (int i = 0; i < m; ++i){
		cin >> u >> v >> c;
		g[u].push_back({c,v});
		g[v].push_back({v,u});
	}
	int a, b;
	while(cin >> a >> b){
		int cost_min = coste_minimo(g, a, b, w);
		cout << "c(" << a << "," << b << ") = ";
		if (cost_min == infinit) cout << "+oo" << endl;
		else cout << cost_min << endl;
	}

}