#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef vector<vector<char>> Mapa;
typedef pair<int, int> pos;
typedef pair<int, pos> dist_pos;

const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};

int INT_MAX = 1000000;

int bfs(Mapa& map, int f, int c){
	queue<dist_pos> q;
	int dist = INT_MAX;
	q.push(dist_pos(0,{f,c}));
	map[f][c] = 'X';
	while(not q.empty()){
		dist_pos dp = q.front();
		q.pop();
		pos p = dp.second;
		int d = dp.first;
		for (int i = 0; i < 4; ++i){
			int x = p.first + X[i];
			int y = p.second + Y[i];
			if (x >= 0 and y >= 0 and x < map.size() and y < map[0].size()){
				if (map[x][y] != 'X'){
					if (map[x][y] == 't'){
						if (dist > d+1) dist = d+1;
					}
					q.push(dist_pos(d+1,{x,y}));
					map[x][y] = 'X';
				}
			}
		}
	}
	return dist;
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
	int res = bfs(map, f-1, c-1);
	if (res != 0) cout << "distancia maxima: " << res << endl;
	else cout << "no es pot arribar a cap tresor" << endl;
}