#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<string>> Tablero;
typedef vector<vector<int>> t_dist;
typedef pair<int, int> Pos;

const vector<Pos> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};


bool pos_ok(Pos seg, int n, int m){
	return seg.first >= 0 and seg.first < n and seg.second >= 0 and seg.second < m;
}

int bfs(const Tablero& t, string& s, Pos& ini, int n, int m){
	t_dist dist(n, vector<int>(m, -1));
	queue<Pos> q;
	q.push(ini);
	dist[ini.first][ini.second] = 0;

	while(not q.empty()){
		Pos act = q.front();
		q.pop();
		if(t[act.first][act.second] == s){
			ini = act; //actualizo la posicion inicial en cada busqueda del elemento encontrado
			return dist[act.first][act.second];
		} 
		else{
			for (int i = 0; i < 4; ++i){
				Pos seg;
				seg.first = act.first + dirs[i].first;
				seg.second = act.second + dirs[i].second;
				if (pos_ok(seg, n, m) and t[seg.first][seg.second] != "*" 
					and dist[seg.first][seg.second] == -1){
					q.push(seg);
					dist[seg.first][seg.second] = dist[act.first][act.second] + 1;
				}
			}
		}
	}
	return -1;
}


int main(){
	int n, m;
	while (cin >> n >> m){
		Tablero t(n, vector<string>(m));
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> t[i][j];
			}
		}
		int tam;
		cin >> tam;
		vector<string> busca(tam);
		for (int i = 0; i < tam; ++i) cin >> busca[i];
		//Tablero t(n, vector<bool>(m, false));

		int suma = 0;
		bool fin = false;
		Pos ini = {0,0};
		int i = 0;
		while(i < tam and not fin){
			int dist = bfs(t, busca[i], ini, n ,m);
			if (dist == -1) fin = true;
			else suma += dist;
			++i;
		}

		if (fin) cout << "impossible" << endl;
		else cout << suma+tam << endl;

	}

}