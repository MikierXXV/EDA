#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ArcP;
typedef vector<vector<int>> Graf;


vector<int> topo(Graf& g, int n, int m){
	vector<int> ge(n, 0);
	for (int i = 0; i < n; ++i){
		for (int v : g[i]){
			++ge[v];
		}
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; ++i){
		for (int v : g[i]){
			if (ge[i] == 0) pq.push(v);
		}
	}
	
	vector<int> sol;

	while (not pq.empty()){
		int u = pq.top();
		pq.pop();
		sol.push_back(u);
		for (int v : g[u]){
			--ge[v];
			if (ge[v] == 0) pq.push(v);
		}
	}

	return sol;
}

int main(){

	int n, m;
	while(cin >> n >> m){
		Graf g(n);
		for (int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int> sol = topo(g, n, m); 
		for (int i = 0; i < sol.size(); ++i){
			if(i != 0) cout << " ";
			cout << sol[i];
		}
		cout << endl;
	}
}