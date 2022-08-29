#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
typedef vector<vector<int>> Grafo;

vector<bool> vis;

bool dfs(const Grafo& g, int u) {
	int n = g.size();
	vector<bool> vis_u(n, false);
	stack<int> S;
	S.push(u);
	vis_u[u] = true;
	while (not S.empty()) {
		int v = S.top();
		S.pop();
		for (int z: g[v]) {
			if (z == u) return true;
			if (not vis_u[z]) {
				vis_u[z] = true;
				S.push(z);
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
		if (not vis[i]) {
			vis[i] = true;
			if (dfs(g, i)) return true;
		}
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
        vis = vector<bool>(n, false);
        if (es_ciclic(g)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
