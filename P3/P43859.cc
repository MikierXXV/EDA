#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <limits>
using namespace std;

const int infinit = numeric_limits<double>::infinity();

typedef pair<int, int> arco;
typedef vector<vector<arco>> Grafo;


void dijkstra(Grafo& G, int x, int y, vector<int>& dist, vector<int>& camino){
	int n = G.size();
	vector<bool> visto(n, false);
	dist[x] = 0;
	priority_queue<arco, vector<arco>, greater<arco>> CP; 
	CP.push(arco(0, x));
	bool fin = false;
	while(not CP.empty() and not fin){
		int v = CP.top().second;
		CP.pop();
		if (not visto[v]){
			visto[v] = true;
			for (int i = 0; i < G[v].size(); ++i){
				int w = G[v][i].second;
				int d = G[v][i].first;
				if (not visto[w]){
					if (dist[w] == infinit or dist[w] > dist[v]+d){
						dist[w] = dist[v]+d;
						CP.push(arco(dist[w], w));
						camino[w] = v;
					}
				}
			}
		}
		else if (v == y) fin = true;
	}
}

int main(){
	int n, m;
	while(cin >> n >> m){
		Grafo G(n);
		for (int i = 0; i < m; ++i){
			int u, v, c;
			cin >> u >> v >> c;
			G[u].push_back(arco(c, v));
		}
		int x, y;
		cin >> x >> y;
		vector<int> distancia(n, infinit);
		vector<int> camino(n, -1);
		dijkstra(G, x, y, distancia, camino);
		if (distancia[y] != infinit) cout << distancia[y] << endl;
		else cout << "no path from " << x << " to " << y << endl;
	}
}