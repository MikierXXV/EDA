#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

typedef vector<vector<int>> Graf;


vector<int> topo(const Graf& g, int n, int m){
	//miro grados de adyecencia
	vector<int> ge(n, 0);
	for(int u = 0; u < n; ++u){
		for (int v : g[u]) ++ge[v];
	}
	//los de grado 0 los meto en pila
	stack<int> s;
	for (int u = 0; u < n; ++u){
		if (ge[u] == 0) s.push(u);
	}
	vector<int> l;
	while(not s.empty()){
		int u = s.top();
		s.pop();
		l.push_back(u);
		for (int v : g[u]){
			if (--ge[v] == 0) s.push(v);
		}
	}
	return l;
}


int main(){
	int n, m;
	while(cin >> n >> m){
		Graf g(n);
		int x, y;
		for (int i = 0; i < m; ++i){
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		vector<int> l = topo(g, n, m);
		if (l.size() > 0){
			for (int i = 0; i < l.size(); ++i){
				if (i == 0) cout << l[i];
				else cout << ' ' << l[i];
			}
			cout << endl;
		}
		else cout << 0 << endl;
	}
}