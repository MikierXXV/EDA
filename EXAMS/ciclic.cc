#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graf;


bool es_ciclic(const Graf& g, int n, int m){
	vector<int> grad(n, 0);
	for (int u = 0; u < n; ++u){
		for (int v: g[u]) ++grad[v];
	}
	queue<int> q;
	for (int i = 0; i < n; ++i){
		if(grad[i] == 0) q.push(i);
	}
	while(not q.empty()){
		int u = q.front();
		q.pop();
		--n;
		for (int v : g[u]){
			--grad[v];
			if (grad[v] == 0) q.push(v);
		}
	}
	return n > 0;
}

int main(){
	int n, m;
	while (cin >> n >> m){
		Graf g(n);
		for (int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
		}
		if(es_ciclic(g, n, m)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}