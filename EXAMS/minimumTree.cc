#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ArcP;
typedef vector<vector<ArcP>> Graf;


int minimum(const Graf& g, int n){
	vector<bool> vis(n, false);
	vis[0] = true;

	priority_queue<ArcP, vector<ArcP>, greater<ArcP>> pq;

	// añado arcos adyecentes al vertice de origen
	for(ArcP p: g[0]) pq.push(p);
	int tam = 1;
	int res = 0;

	//miro todo los vertices
	while(tam < n){
		int u = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		//si no visitado verice
		if(not vis[u]){
			vis[u] = true;
			//miro arcos adyecentes y encolo
			for(ArcP p: g[u]){
				pq.push(p);
			}
			//actualizar tamaño y suma de pesos
			++tam;
			res += dist;
		}
	}
	return res;
}

int main(){

	int n, m;
	while(cin >> n >> m){
		Graf g(n);
		int u, v, w;
		for (int i = 0; i < m; ++i){
			cin >> u >> v >> w;
			g[u-1].push_back({w, v-1});
			g[v-1].push_back({w, u-1});
		}
		cout << minimum(g, n) << endl;
	}
}