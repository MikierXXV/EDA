#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

const int X[4] = {1, 0, -1, 0};
const int Y[4] = {0, 1, 0, -1};

typedef vector<vector<char>> Mapa;
typedef vector<vector<int>> Mapa_int;
typedef pair<int,int> parint;

bool pos_ok (int x, int y, Mapa& mapa) {
	int n = mapa.size();
	int m = mapa[0].size();
	return x >= 0 and x < n and y >= 0 and y < m and mapa[x][y] != '#';
}

parint BFS(Mapa& mapa, int n, int m) {
	if (mapa[0][0] == 'T') return {0, 0};
	
	Mapa_int dist(n, vector<int>(m, INT_MAX));
	Mapa_int pers(n, vector<int>(m, 0));
	queue<parint> Q;
	
	if (mapa[0][0] == 'P') ++pers[0][0];
	Q.push({0,0});
	dist[0][0] = 0;
	
	while (not Q.empty()) {
		parint p = Q.front();
		Q.pop();
		
		if (mapa[p.first][p.second] == 'T') return {dist[p.first][p.second], pers[p.first][p.second]};
		//cout << "Pos " << p.first << ", " << p.second << " dist " << d << " pers " << np << endl;
		for (int i = 0; i < 4; ++i) {
			int x = p.first + X[i];
			int y = p.second + Y[i];
			int d = dist[p.first][p.second];
			int np = pers[p.first][p.second];
			if (pos_ok(x, y, mapa)) {
				//cout << "Pos ok " << x << ", " << y << endl;
				++d;
				if (mapa[x][y] == 'P') ++np;
				if (dist[x][y] == INT_MAX) {
					dist[x][y] = d;
					pers[x][y] = np;
					Q.push({x,y});
				}
				else if (dist[x][y] == d and np > pers[x][y]) {
					pers[x][y] = np;
				}
			}
		}
	}
	return {-1, -1};
}

int main (){
	int n, m;
	while (cin >> n >> m) {
		Mapa mapa(n, vector<char>(m));
		bool esta = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> mapa[i][j];
				if (mapa[i][j] == 'T') esta = true;
			}
		}
		
		if (not esta) cout << "El telecos ha fugit." << endl;
		else {
			parint res = BFS(mapa, n, m);
			if (res.first == -1) cout << "El telecos esta amagat." << endl;
			else cout << res.first << " " << res.second << endl;
		}
	}
}
