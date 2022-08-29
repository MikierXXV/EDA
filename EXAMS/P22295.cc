#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Mapa;
typedef vector<vector<bool>> Mapa_bool;
typedef pair<int, int> Pos;

const int X[4] = {1, 0, -1, 0};
const int Y[4] = {0, -1, 0, 1};

bool pos_ok(int n, int m, int x, int y) {
	return x >= 0 and x < n and y >= 0 and y < m;
}

void escriu(const Mapa& mapa, const vector<Pos>& camino) {
	for (int i = 0; i < int(camino.size()); ++i) {
		int x = camino[i].first;
		int y = camino[i].second;
		cout << mapa[x][y];
	}
	cout << endl;
}

void backtrack(const Mapa& mapa, vector<Pos>& camino, Mapa_bool& vis, int n, int m, int f_fin, int c_fin) {
	Pos act = camino.back();
	if (act.first == f_fin and act.second == c_fin) escriu(mapa, camino);
	else {
		for (int i = 0; i < 4; ++i) {
			int x = act.first + X[i];
			int y = act.second + Y[i];
			if (pos_ok(n, m, x, y) and not vis[x][y]) {
				camino.push_back({x, y});
				vis[x][y] = true;
				backtrack(mapa, camino, vis, n, m, f_fin, c_fin);
				vis[x][y] = false;
				camino.pop_back();
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	Mapa mapa(n, vector<char>(m));
	Mapa_bool vis(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> mapa[i][j];
	}
	
	//Pos ini, fin;
	//cin >> ini.first >> ini.second >> fin.first >> fin.second;
	int f_ini, c_ini, f_fin, c_fin;
	cin >> f_ini >> c_ini >> f_fin >> c_fin;
	
	vector<Pos> camino(1, Pos(f_ini, c_ini));
	vis[f_ini][c_ini] = true;
	backtrack(mapa, camino, vis, n, m, f_fin, c_fin);
}