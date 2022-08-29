#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef vector<vector<bool>> Tab_bool;
typedef pair<int, int> Pos;

const vector<Pos> dirs_a = {{-1,1}, {1,1}, {1,-1}, {-1,-1}};
const vector<Pos> dirs_c = {{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}}; 


bool pos_ok(Pos seg, int n, int m){
	return seg.first >= 0 and seg.first < n and seg.second >= 0 and seg.second < m;
}


int bfs(int n, int m, Tablero& t, Tab_bool& vis_B, queue<Pos>& alfils){
	int suma = 0; 
	while(not alfils.empty()){
		Pos act = alfils.front();
		alfils.pop();
		for (int i = 0; i < 4; ++i){
			Pos seg;
			seg.first = act.first + dirs_a[i].first;
			seg.second = act.second + dirs_a[i].second;
			if(pos_ok(seg, n, m) and t[seg.first][seg.second] != 'T' and not vis_B[seg.first][seg.second]){
				vis_B[seg.first][seg.second] = true;
				alfils.push(seg);
				if (t[seg.first][seg.second] != '.' and t[seg.first][seg.second] != 'B' and t[seg.first][seg.second] != 'K'){
					suma += t[seg.first][seg.second] - '0';
					t[seg.first][seg.second] = '.';
				}
			}
		}
	}
	return suma;
}

int bfs1(int n, int m, Tablero& t, Tab_bool& vis_K, queue<Pos>& caballs){
	int suma = 0; 
	while(not caballs.empty()){
		Pos act = caballs.front();
		caballs.pop();
		for (int i = 0; i < 8; ++i){
			Pos seg;
			seg.first = act.first + dirs_c[i].first;
			seg.second = act.second + dirs_c[i].second;
			if(pos_ok(seg, n, m) and t[seg.first][seg.second] != 'T' and not vis_K[seg.first][seg.second]){
				vis_K[seg.first][seg.second] = true;
				caballs.push(seg);
				if (t[seg.first][seg.second] != '.' and t[seg.first][seg.second] != 'B' and t[seg.first][seg.second] != 'K'){
					suma += t[seg.first][seg.second] - '0';
					t[seg.first][seg.second] = '.';
				}
			}
		}
	}
	return suma;
}

int main(){
	int n, m;
	while(cin >> n >> m){
		Tablero t(n, vector<char>(m));
		Tab_bool vis_B(n, vector<bool>(m));
		Tab_bool vis_K(n, vector<bool>(m));
		queue<Pos> alfils;
		queue<Pos> caballs;
		for (int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> t[i][j];
				if (t[i][j] == 'B'){
					alfils.push({i,j});
					vis_B[i][j] = true;
				} 
				if (t[i][j] == 'K'){
					caballs.push({i,j});
					vis_K[i][j] = true;
				}	
			}
		}
		int suma = bfs(n, m, t, vis_B, alfils);
		suma += bfs1(n, m, t, vis_K, caballs);
		cout << suma << endl;
	}
}