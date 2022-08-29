#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Mapa;
typedef pair<int, int> pos;
const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};

bool posicion(int f, int c, Mapa& map){
	if (f < 0 or c < 0 or f >= map.size() or c >= map[0].size()) return false;
	else if(map[f][c] == 'X') return false;
	else return true;
}

void dfs(Mapa& map, int f, int c, int& suma){
	if(posicion(f, c, map)){
		if(map[f][c] == 't'){
			++suma;
			map[f][c] = 'X';
		}
		for (int i = 0; i < 4; ++i){
			map[f][c] = 'X';
			dfs(map, f+X[i], c+Y[i], suma);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	Mapa map(n, vector<char>(m));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j) cin >> map[i][j];
	}
	int f, c;
	cin >> f >> c;
	int suma = 0;
	dfs(map, f-1, c-1, suma);
	cout << suma << endl;
}