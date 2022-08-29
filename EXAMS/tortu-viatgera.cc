#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<char, bool> Par;
typedef	pair<int, int> Pos;
typedef vector<vector<Par>> Tablero;

const vector<Pos> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

bool pos_ok(Pos seg, int n, int m){
	return seg.first >= 0 and seg.second >= 0 and seg.first < n and seg.second < m;
}

void escriu(const vector<char>& sol){
	for (int i = 0; i < sol.size(); ++i){
		cout << sol[i];
	}
	cout << endl;
}


void back_track(Tablero& t, vector<char>& sol, Pos ini, Pos fin, int n, int m){
	if(ini == fin) escriu(sol);
	else{
		for (int k = 0; k < 4; ++k){
			Pos seg;
			seg.first = ini.first + dirs[k].first;
			seg.second = ini.second + dirs[k].second;
			if(pos_ok(seg, n, m) and not t[seg.first][seg.second].second){
				sol.push_back(t[seg.first][seg.second].first);
				t[seg.first][seg.second].second = true;

				back_track(t, sol, seg, fin, n, m);

				sol.pop_back();
				t[seg.first][seg.second].second = false;
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	Tablero t(n, vector<Par>(m));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> t[i][j].first;
			t[i][j].second = false;
		}
	}
	int x, y, w, z;
	cin >> x >> y >> w >> z;
	Pos ini = {x, y};
	Pos fin = {w, z};
	t[x][y].second = true;
	vector<char> sol = {t[x][y].first};
	back_track(t, sol, ini, fin, n, m);
}