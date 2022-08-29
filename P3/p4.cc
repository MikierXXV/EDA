#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <limits>
using namespace std;

typedef pair<int, int> ArcP;
typedef vector<vector<ArcP>> Graf;


const int infinit = numeric_limits<double>::infinity();

void dijkstra(Graf& g, int u, int dest, vector<int>& distancia, vector<int>& camino){
	int n = g.size();
	vector<bool> vis(n, false);
	distancia[u] = 0;
	priority_queue<ArcP, vector<ArcP>, greater<ArcP>> CP;
	CP.push({0, u});
	while(not CP.empty()){
		int v = CP.top().second;
		CP.pop();
		if (not vis[v]){
			vis[v] = true;
			for (int i = 0; i < g[v].size(); ++i){
				int w = g[v][i].second;
				int d = g[v][i].first;
				if (distancia[w] == infinit or distancia[w] > distancia[v] + d){
					distancia[w] = distancia[v]+d;
					CP.push({distancia[w], w});
					camino[w] = v;

				}
			}
		}
	}
}

//PORQUE SI IMPIMO CAMINO A SECAS SALE OTRO A LA SOLUCION?
void escriu(vector<int>& v, int ori, int dest) {
   if (ori != dest) {
      escriu(v, ori, v[dest]);
      cout << v[dest] << " ";
   }
}

int main(){
	int n, m;
	while (cin >> n >> m){
		Graf g(n);
		int u, v, c;
		for (int i = 0; i < m; ++i){
			cin >> u >> v >> c;
			g[u].push_back({c, v});
		}
		int ori, dest;
		cin >> ori >> dest;
		vector<int> distancia(n, infinit);
		vector<int> camino(n, -1);
		vector<int> minpath;
		dijkstra(g, ori, dest, distancia, camino);

		if(distancia[dest] != infinit) {
         escriu(camino, ori, dest);
         cout <<  dest << endl;
      	}
      	else cout << "no path from " << ori << " to " << dest << endl;

	}
}