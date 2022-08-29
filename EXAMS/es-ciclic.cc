#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef vector<vector<int>> Graf;

bool es_ciclic(Graf& g){
	int n = g.size();
	vector<int> ge(n, 0);
	for (int i = 0; i < n; ++i){
		for (int v : g[i])
			++ge[v];
	}

	queue<int> q;
	for (int i = 0; i < n; ++i){
		if(ge[i] == 0) q.push(i);
	}

	while(not q.empty()){
		int u = q.front();
		q.pop();

		--n; //visitado vertice nuevo

		for (int v: g[u]){
			--ge[v];
			if (ge[v] == 0) q.push(v);
		}
	}

	return n > 0; //si no he visitado todos los vertices hay ciclo
}

int main(){
	int n, m;
	while(cin >> n >> m){
		Graf g(n);

		for(int i = 0; i < m; ++i){
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
		}

		if(es_ciclic(g)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}