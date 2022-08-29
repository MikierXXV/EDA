#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef vector<vector<int>> Graf;

bool pinta(const Graf& g, int u, int col, vector<int>& colors){
	bool color;
	if(colors[u] == -1){
		colors[u] = col;
		color = true;
		int i = 0; 
		while (i < g[u].size() and color){
			color = pinta(g, g[u][i], 1-col, colors);
			++i;
		}
	}
	else color = (colors[u] == col);
	return color;
}

bool dos_colors(const Graf& g, int n){
	bool col = true;
	vector<int> colors(n, -1);
	int i = 0;
	while (i < n and col){
		if (colors[i] == -1) col = pinta(g, i, 0, colors);
		++i;
	}
	return col;
}

int main(){
	int n, m;
	while (cin >> n >> m){
		int u, v;
		Graf g(n);
		for (int i = 0; i < m; ++i){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		bool col = dos_colors(g, n);
		cout << (col? "yes" : "no") << endl;
	}
} 