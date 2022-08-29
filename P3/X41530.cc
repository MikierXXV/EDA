#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graf;

void cicles(const Graf& g, vector<bool>& vis, int i, int padre, bool& b){
	if(not vis[i]){
		vis[i] = true;
		for (int arista : g[i]){
			if(arista != padre) cicles(g, vis, arista, i, b);
			if (b) return;
		}
	}
	else b = true;
}

void dfs(const Graf& g){
	vector<bool> vis(g.size(), false);
	int arbres = 0;
	for (int i = 0; i < g.size(); ++i){
		if(not vis[i]){
			bool b = false;
			cicles(g, vis, i, i, b);
			if(b){
				cout << "no" << endl;
				return;
			}
			else ++arbres;
		}
	}
	cout << arbres << endl;
}

int main(){
	int n, m;
	while(cin >> n >> m){
		int x, y;
		Graf G(n);
		for (int i = 0; i < m; ++i){
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(G);
	}
}