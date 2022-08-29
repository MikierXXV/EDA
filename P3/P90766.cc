#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Mapa;
typedef vector<vector<bool>> Mapa_vis;
typedef pair<int, int> pos;
const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};


int bfs(const Mapa& map, int f, int c, Mapa_vis& map_v){
	int tresors = 0;
	pos ini = {f,c};
	queue<pos> q;
	q.push(ini);
	while(not map_v[][j] and not q.empty()){


	}
}

int main() {
	int n, m;
	cin >> n >> m;
	Mapa map(n, vector<char>(m));
	Mapa_vis map_v(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> map[i][j];
			if(map[i][j] == 'X') map_v[i][j] = true;
		} 
	}
	int f, c;
	cin >> f >> c;
	cout << bfs(map, f, c, map_v) << endl;
}