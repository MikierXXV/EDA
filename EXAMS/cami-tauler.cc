#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Tablero;
typedef pair<int, int> Pos;

const vector<Pos> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int min(const vector<pair<int, int>>& costes){
	pair<int, int> res = costes[0];
	for (int i = 1; i < 4; ++i){
		if (costes[i].first < res.first){
			res.first = costes[i].first;
			res.second = costes[i].second;
		} 
	}
	return res.second;
}

bool pos_ok(Pos seg, int n){
	return seg.first >= 0 and seg.first < n and seg.second >= 0 and seg.second < n;
}

int bfs(Tablero& t, Pos ini, int& cost, vector<pair<int,int>>& costes, int n){
	queue<Pos> q;
	q.push(ini);
	t[ini.first][ini.second] = -1;

	int res = cost;
	//cout << res << endl;
	while(not q.empty()){
		Pos act = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i){
			Pos seg;
			seg.first = act.first + dirs[i].first;
			seg.second = act.second + dirs[i].second;
			if (pos_ok(seg, n)) costes[i].first = t[seg.first][seg.second];
		}
		int pos = min(costes);
		Pos mueve = {dirs[pos].first + act.first, dirs[pos].second + act.second};
		if (pos_ok(mueve, n) and t[mueve.first][mueve.second] != -1){
			res += t[mueve.first][mueve.second];
			q.push(mueve);
			t[act.first][act.second] = -1;
		}
	}
	return res;
}



int main(){
	int n;
	while(cin >> n){
		Tablero t(n, vector<int>(n));
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				cin >> t[i][j];
			}
		}
		int cost = t[0][0];
		if (n > 1){
			cost = t[(n/2)][(n/2)];
		}
		cout << cost << endl;
		Pos ini = {(n/2), (n/2)};
		vector<pair<int, int>> costes(4);
		for (int i = 0; i < 4; ++i) costes[i] = {cost, i};
		int res = bfs(t, ini, cost, costes, n);
		cout << res << endl;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				cout << t[i][j];
				cout << endl;
		}
		cout << endl;

	}

}