#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef map<string, int> Map_index;
typedef vector<vector<int>> Dependencias;

void orden_topologica(Dependencias& Tareas,vector<int>& incid, vector<string>& nombres, Map_index& pos_tareas,queue<string> orden){
	int n = Tareas.size();
	priority_queue<string, vector<string>, greater<string>> pq;  //oredeno de menor a mayor (por defecto es al reves)

	for(int i = 0; i < n; ++i){
		if (incid[i] == 0) pq.push(nombres[i]);
	}	
	while (not pq.empty()){
		int u = pos_tareas[pq.top()];
		pq.pop();
		orden.push(nombres[u]);
		for (int i = 0; i < Tareas[u].size(); ++i){
			int v = Tareas[u][i];
			if (--incid[v] == 0) pq.push(nombres[v]);
		}
	}
}
 
int main(){
	int n;
	while (cin >> n){
		Map_index pos_tareas; 		// guardo nombre y la pos de la tarea ordenad
		vector<string> nombres(n);
		for (int i = 0; i < n; ++i){
			string nom;
			cin >> nom;
			nombres[i] = nom;
			pos_tareas[nom] = i;  //m.insert(pair<string, int>(nom,i));
		}
		int m;
		cin >> m;
		Dependencias Tareas(n);
		vector<int> incid(n,0);
		for (int i = 0; i < n; ++i){
			string u, v;
			cin >> u >> v;
			int pos_u = pos_tareas[u];
			int pos_v = pos_tareas[v];
			Tareas[pos_u].push_back(pos_v);
			++incid[pos_v];
		}

		queue<string> orden;
		orden_topologica(Tareas,incid,nombres,pos_tareas,orden);
		if(orden.size() == nombres.size()){
			while (not orden.empty()){
				cout << orden.front();
				orden.pop();
			}
			cout << endl;
		}
		else cout << "NO VALID ORDERING" << endl;
	}
}