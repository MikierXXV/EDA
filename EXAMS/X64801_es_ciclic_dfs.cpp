#include <iostream>
#include <vector>
using namespace std;
 
typedef vector<vector<int>> Grafo;


bool dfs(const Grafo& g, int u, int ini, vector<bool>& vis_v) {
	if (not vis_v[u]){
		vis_v[u] = true;
		for (int v: g[u]) {
			if (v == ini) return true;
			else if (not vis_v[v]) {
				if (dfs(g, v, ini, vis_v)) return true;
			}
		}
	}
	return false;
}

bool es_ciclic(const Grafo& g) {
	int n = g.size();
	
	bool cicle = false;
	int i = 0; 
	while (i < n) {
		vector<bool> vis_v(n, false);
		if (dfs(g, i, i, vis_v)) return true;
		++i;
	}
	return false;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        Grafo g(n);
		       
        int x,y;
        for (int i = 0; i < m; ++i){
            cin >> x >> y;
            g[x].push_back(y); // x es adyacente a y
        }
        
        if (es_ciclic(g)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
