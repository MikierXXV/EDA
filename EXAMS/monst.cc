#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef pair<int, int> Pos;

const vector<Pos> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool pos_ok(Pos p, int n, int m){
	return p.first >= 0 and p.first < n and p.second >= 0 and p.second < m;
}

bool dfg(Tablero& t, Pos ini, Pos fin, int n , int m){
	if (ini == fin) return true;
	else{
		for (int i = 0; i < 4; ++i){
			Pos seg;
			seg.first = ini.first + dirs[i].first;
			seg.second = ini.second + dirs[i].second;
			if (pos_ok(seg, n, m) and t[seg.first][seg.second] != 'X'){
				t[seg.first][seg.second] = 'X';
				if (dfg(t, seg, fin, n, m)) return true;
				//dfg(t, seg, fin, n, m);
			} 
		}
	}
	return false;
}


int main(){

	int n, m;
	while(cin >> n >> m){
		Tablero t(n, vector<char>(m));
		vector<Pos> monst;
		Pos ini, fin;
		for(int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> t[i][j];
				if (t[i][j] == 'I') ini = {i,j};
				else if (t[i][j] == 'F') fin = {i,j};
				else if (t[i][j] == 'M') monst.push_back({i,j});
			}
		}
		//cout <<"LLego" << endl;
		for (int i = 0; i < monst.size(); ++i){
			Pos p = monst[i];
			for (int j = 0; j < 4; ++j){
				Pos seg;
				seg.first = p.first + dirs[j].first;
				seg.second = p.second + dirs[j].second;
				if (pos_ok(seg, n, m) and t[seg.first][seg.second] != 'M')
					t[seg.first][seg.second] = 'X';
			}
			//cout <<"Ejecuto" << endl;
		}
		//cout <<"evaluo" << endl;
		if (dfg(t, ini, fin, n, m)) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}
