#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <limits>
using namespace std;

const int infinit = numeric_limits<double>::infinity();

typedef pair<int, int> arista;
typedef vector<vector<arista>> Grafo;

void dijkstra(Grafo& G, int ori, vector<int>& dist, vector<int>& camino, int dest){
	int n = G.size();
	vector<bool> visto(n, false);
	dist[ori] = 0;
	priority_queue<arista, vector<arista>, greater<arista>> pq;
	pq.push(arista(0, ori));
	bool fin = false;
	while (not pq.empty() and not fin){
		int v = pq.top().second;
		pq.pop();
		if (not visto[v]) {
			visto[v] = true;
			for (int i = 0; i < G[v].size(); ++i){
				int w = G[v][i].second;
               	int d = G[v][i].first;
               	if (not visto[w]){
					if (dist[w] == infinit or dist[w] > dist[v]+d){
						dist[w] = dist[v]+d;
						pq.push(arista(dist[w],w));
						camino[w] = v;
					}
				}
			}
		}
		else if (v == dest) fin = true;
	}	 
}

void escriu(vector<int>& v, int ori, int dest){
	if (ori != dest){
		escriu(v,ori,v[dest]);
		cout << v[dest] << " ";
	}
}

int main(){
	int n, m;
	while(cin >> n >> m){
		Grafo G(n);
		for (int i = 0; i < n; ++i){
			int u, w, p;
			cin >> u >> w >> p;
			G[u].push_back(arista(p,w));
		}
		int ori, dest;
		cin >> ori >> dest;
		vector<int> distancia(n, infinit);
		vector<int> camino(n, -1);
		dijkstra(G,ori,distancia,camino,dest);
		if (distancia[dest] != infinit){
			escriu(camino,ori,dest);
			cout << dest << endl;
		}
		else cout << "no path from " << ori << " to " << dest << endl;
	}
}
