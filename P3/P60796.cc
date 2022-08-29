#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Mapa;
typedef pair<int, int> pos;
const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};


void bfs(Mapa& map, int f, int c, int& min){
	bool trobat = false;
	queue<pos> q;
	q.push({f,c});
	if (map[f][c] == 't') return;
	map[f][c] = 'v';
	int cont = 1;
	bool primer = true;
	while (not q.empty()){
		pos p = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i){
			int x = p.first + X[i];
			int y = p.second + Y[i];
			if (x >= 0 and y >= 0 and x < map.size() and y < map[0].size()){
				if (map[x][y] == 't' and primer){
					trobat = true;
					min = cont;
					primer = false;
				}
				if (map[x][y] == 't' and not primer){
					trobat = true;
					if (cont < min) min = cont;
				}
				else if (map[x][y] == '.'){
					map[p.first][p.second] = 'v';
					++cont;
					q.push({x,y});
				}
			}
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
	int f, c, min = 0;
	cin >> f >> c;
	bfs(map, f-1, c-1, min);
	if (min == 0) cout << "no es pot arribar a cap tresor" << endl;
	else cout << "distancia minima: " << min << endl;
}