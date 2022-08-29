#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef pair<int, int> Pos;

const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};

//MIRAR SEGUNDO CASO

bool dfs(Tablero& t, vector<Pos>& tresors, Pos& ini, int n, int m){
	bool trobat = false;
	stack<Pos> s;
	s.push(ini);
	t[ini.first][ini.second] = 'X';
	if (tresors.size() > 0){
		for (int i = 0; i < int(tresors.size()); ++i){
			s.push(tresors[i]);
		}
	}
	
	while(not trobat and not s.empty()){
		Pos p = s.top();
		s.pop();
		for (int i = 0; i < 4 and not trobat; ++i){
			int x = p.first + X[i];
			int y = p.second + Y[i];
			if(x >= 0 and x < n and y >= 0 and y < m and t[x][y] != 'X'){
				if (t[x][y] == 't') trobat = true;
				else if (t[x][y] == '.'){
					t[p.first][p.second] = 'X';
					s.push({x,y});
				}
			}
		}
	}
	return trobat;
}


int main(){
	int n, m;
	cin >> n >> m;
	bool exist_t = false;
	Tablero t(n, vector<char>(m));
	vector<Pos> tresors; 
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j) {
			cin >> t[i][j]; 
			if (t[i][j] == 't'){
				exist_t = true;
				tresors.push_back({i,j});
			} 
		}
	}
	int x, y;
	cin >> x >> y;
	Pos ini = {x-1,y-1};

	bool b = dfs(t, tresors, ini, n, m);
	cout << (b? "yes":"no") << endl;


}