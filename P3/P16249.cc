#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef vector<int> vec_int;
typedef vector<string> vec_nom;
typedef vector<vec_int> Graf;
typedef map<string, int> map_index;


void ordenacio_topo(Graf& tareas, vec_int& incidentes, map_index& pos_tareas,
 vec_nom& nombres, queue<string> orden){

	int n = tareas.size();
	priority_queue<string, vector<string>, greater<string>> pq;

	for (int i = 0; i < n; ++i){
		if (incidentes[i] == 0) pq.push(nombres[i]);
		while (not pq.empty()){
			int u = pos_tareas[pq.top()];
			pq.pop();
			orden.push(nombres[u]);
			int m = tareas[u].size();
			for (int i = 0; i < m; ++i){
				int v = tareas[u][i];
				if (--incidentes[v] == 0) pq.push(nombres[v]);
			}
		}
	}
}

int main(){

	int n;
	while (cin >> n){
		map_index pos_tareas;
		vec_nom nombres(n);

		for (i = 0; i < n; ++i){
			string n;
			cin >> nom;
			nombres[i] = nom;
			pos_tareas[nom] = i;
		}

		int m;
		cin >> m; 
		Graf tareas(n);
		vec_int incidentes(n, 0);

		for (int i = 0; i < m; ++i){
			string u, v;
			cin >> u >> v;
			tareas[pos_tareas[u]].push_back(pos_tareas[v]);
			++incidentes[pos_tareas[v]];
		}

		queue<string> orden;
		ordenacio_topo(tareas, incidentes, pos_tareas, nombres, orden);
		if (orden.size() == nombres.size()){
			while(not orden.empty()){
				cout << orden.front();
				orden.pop();
			}
		}
		else cout << "NO VALID ORDERING" << endl;
	}
}