#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<char, int> Par;
typedef pair<int, int> Pos;
typedef vector<vector<Par>> Tablero;


const vector<Pos> dirs = {{-2,-1}, {-1,-2}, {2,1}, {1,2}, {2,-1}, {1, -2}, {-2,1}, {-1,2}};

bool pos_ok(Pos seg, int n, int m){
	return seg.first >= 0 and seg.first < n and seg.second >= 0 and seg.second < m;
}

int bfs(Tablero& t, Pos ini, int n, int m){
	queue<Pos> q;
	q.push(ini);
	//t[ini.first][ini.second] = 'X';

	while(not q.empty()){
		Pos act = q.front();
		q.pop();
		if(t[act.first][act.second].first == 'p') return t[act.first][act.second].second;
		else if(t[act.first][act.second].first != 'X'){
			t[act.first][act.second].first = 'X';
			int dist = t[act.first][act.second].second;
			for (int i = 0; i < 8; ++i){
				Pos seg;
				seg.first = act.first + dirs[i].first;
				seg.second = act.second + dirs[i].second;
				if(pos_ok(seg, n, m) and t[seg.first][seg.second].first != 'X'){
					t[seg.first][seg.second].second = dist+1;
					q.push(seg);
				}
			}
		}
	}
	return -1;
}


int main(){

	int n, m; 
	while(cin >> n >> m){
		Tablero t(n, vector<Par>(m));
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> t[i][j].first;
				t[i][j].second = 0;
				
			}
		}
		int x, y;
		cin >> x >> y;
		Pos ini = {x-1,y-1};

	 	int res =  bfs(t, ini, n, m);
	 	if (res == -1) cout << "no" << endl;
	 	else cout << res << endl;
	}
}