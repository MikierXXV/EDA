#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef vector<vector<char>> Mapa;
const int X[4] = {0, 1, 0 ,-1};
const int Y[4] = {1, 0, -1, 0};
typedef pair<int, int> pos;

bool bfs(Mapa& map, int f , int c){
	bool trobat = false;
	queue<pos> q;
	q.push({f,c});
	map[f][c] = 'v';
	while(not trobat and not q.empty()){
		pos p = q.front();
		q.pop();
		for(int i = 0; i < 4 and not trobat; ++i){
			int x = p.first + X[i];
			int y = p.second + Y[i];
			if (x >= 0 and x < map.size() and y >= 0 and y < map[0].size()){
				if (map[x][y] == 't') trobat = true;
				else if (map[x][y] == '.'){
					map[p.first][p.second] = 'v';
					q.push({x,y});
				}
			}
		}
	}
	return trobat;
}

int main(){

	int n, m;
	cin >> n >> m;
	Mapa map(n, vector<char>(m));
	vector<pos> obst;

	int cont_t = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j) cin >> map[i][j];
	}

	int f, c;
	cin >> f >> c;
	bool trobat = bfs(map, f-1, c-1);
	cout << (trobat? "yes" : "no") << endl;

}