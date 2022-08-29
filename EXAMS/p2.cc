#include <iostream>
#include <vector>
using namespace std;

const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};

typedef vector<vector<char>> Mapa;
typedef pair<int, int> Pos;

bool pos_ok(Pos p, int n, int m){
	return p.first < n and p.first >= 0 and p.second < m and p.second >= 0;
}

bool DFS(Mapa& mapa, Pos ini, Pos fin, int n, int m){
	if (ini == fin) return true;
	else{
		for (int i = 0; i < 4; ++i){
			Pos seg;
			seg.first = ini.first + X[i];
			seg.second = ini.second + Y[i];
			if (pos_ok(seg, n, m) and mapa[seg.first][seg.second] != 'X'){
				mapa[seg.first][seg.second] = 'X';
				if (DFS(mapa, seg, fin, n, m)) return true;
			}
		}
		return false;
	}
}

int main(){
	int n, m;
	while(cin >> n >> m){
		Mapa mapa(n, vector<char>(m));
		vector<Pos> monts;
		Pos ini, fin;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> mapa[i][j];
				if (mapa[i][j] == 'M') monts.push_back({i,j});
				else if(mapa[i][j] == 'I') ini = {i,j};
				else if(mapa[i][j] == 'F') fin = {i,j};

			}
		}

		int x = monts.size();
		for (int i = 0; i < x; ++i){
			Pos act = monts[i];
			for (int j = 0; j < 4; ++j){
				Pos seg;
				seg.first = act.first + X[j];
				seg.second = act.second + Y[j];
				if(pos_ok(seg, n, m) and mapa[seg.first][seg.second] != 'M'){
					mapa[seg.first][seg.second] = 'X';
				}
			}
		}

		if (DFS(mapa, ini, fin, n, m)) cout << "SI" << endl;
		else cout << "NO" << endl;
	}


}