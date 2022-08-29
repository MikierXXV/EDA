#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef pair<int, int> Pos;

const vector<Pos> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
const vector<Pos> dir_fant = {{0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {1,1}, {-1,1}, {1,-1}};

bool bfs(Tablero& t, Pos ini){
	queue<Pos> q;
	q.push(ini);
	t[ini.first][ini.second] = 'X';

	while(not q.empty()){
		Pos p = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i){
			Pos seg;
			seg.first = p.first + dir[i].first;
			seg.second = p.second + dir[i].second;
			if (t[seg.first][seg.second] == 'B') return true;
			else if (t[seg.first][seg.second] == '.'){
				q.push(seg);
				t[seg.first][seg.second] == 'X';
			}
		}
	}
	return false;
}

int main(){
	int n, m;
	while(cin >> n >> m){
		Tablero t(n, vector<char>(m));
		queue<Pos> Ghost;
		Pos ini;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> t[i][j];
				if (t[i][j] == 'F') Ghost.push({i,j});
				else if (t[i][j] == 'P') ini = {i,j};
			}
		}
		bool mort = false;

		while(not Ghost.empty() and not mort){
			Pos p = Ghost.front();
			Ghost.pop();
			for (int j = 0; j < int(dir_fant.size()); ++j){
				Pos seg;
				seg.first = p.first + dir_fant[j].first;
				seg.second = p.second + dir_fant[j].second;
				if (t[seg.first][seg.second] == 'P') mort = true;
				t[seg.first][seg.second] = 'X';
			}
		}
		if (mort) cout << "no" << endl;
		else{
			if (bfs(t, ini)) cout << "si" << endl;
			else cout << "no" << endl;
		}
	}

}