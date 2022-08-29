#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef vector<set<int>> Graf; // guardamos un set para tener las adyacencias ordenadas

void escribir(const vector<int>& v, int u) {
	if (u == 0) cout << u;
	else {
		escribir(v, v[u]);
		cout << " " << u;
	}
}

void bfs(const Graf& g, vector<int>& camino) {
	int n = g.size();
	vector<int> dist(n, -1);
	dist[0] = 0;
	queue<int> Q;
	Q.push(0);
	bool fin = false;
	while (not Q.empty() and not fin) {
		int u = Q.front();
		Q.pop();
		if (u == n-1) fin = true;
		else {
			for (int v: g[u]) {
				if (dist[v] == -1) {
					dist[v] = dist[u] + 1;
					camino[v] = u;
					Q.push(v);
				}
			}
		}
	}
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graf grafo(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            grafo[u].insert(v);
        }
        vector<int> camino(n, -1);
        bfs(grafo, camino);
        escribir(camino, n-1);
        cout << endl;
    }
}
