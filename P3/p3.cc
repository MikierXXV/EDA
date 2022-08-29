#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


typedef vector<vector<char>> Tablero;
typedef pair<int, int> Pos;
typedef pair<int, Pos> Dist;

const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};

//Si ordeno distancias con un set tendira la minima en la primera posicion

int bfs(Tablero& t, int n, int m, int f, int c){
	queue<Dist> q;
	q.push({0, {f, c}});
	t[f][c] = 'X';
	set<int> s;
	while(not q.empty()){
		Dist di = q.front();
		Pos p = di.second;
		int d = di.first;
		for (int i = 0; i < 4; ++i){
			int x = p.first + X[i];
			int y = p.second + Y[i];
			if (X >= 0 and x < n and y >= 0 and y < m){
				if (t[x][y] != 'X'){
					if (t[x][y] == 't'){
						s.insert(d);
					}
					q.push({d+1, {x,y}});
					t[x][y] = 'X';
				}
			}
		}
	}
	if (not s.empty()){
		set<int>::iterator it = s.begin();
		return *(it);
	}
	else return -1;
}


int main(){
	int n, m;
	cin >> n >> m;
	Tablero t(n, vector<char>(m));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> t[i][j];
		}
	}
	int f, c;
	cin >> f >> c;

	int res = bfs(t, n, m, f-1, c-1);
	if(res == -1) cout << "no es pot arribar a cap tresor" << endl;
	else cout << "distancia minima: " << res << endl;
}