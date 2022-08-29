#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Tablero;
typedef pair<int, int> Pos;

const vector<Pos> dirs = {{-2,-1}, {-1,-2}, {2,1}, {1,2}, {2,-1}, {1, -2}, {-2,1}, {-1,2}};

bool pos_ok(Pos seg, int n, int m){
	return seg.first >= 0 and seg.first < n and seg.second >= 0 and seg.second < m;
}


int bfs (int n, int m, Pos ini, Pos fin){
	Tablero dist(n, vector<int>(m, -1));
	queue<Pos> q;
	q.push(ini);
	dist[ini.first][ini.second] = 0;
	//cout << "apunto" << endl;
	while(not q.empty()){
		Pos act = q.front();
		q.pop();
		if (act == fin) return dist[act.first][act.second];
		else{
			for (int i = 0; i < int (dirs.size()); ++i){
				Pos seg;
				seg.first = act.first + dirs[i].first;
				seg.second = act.second + dirs[i].second;
				if (pos_ok(seg, n, m) and dist[seg.first][seg.second] == -1){
					q.push({seg});
					dist[seg.first][seg.second] = dist[act.first][act.second] + 1;
				}
				//return dist[seg.first][seg.second];
			}
		}
	}
	return -1;
}


int main(){
	int n, m, w, l;
	while(cin >> n >> m >> w >> l){
		int k;
		cin >> k;
		vector<Pos> posi(k+1);
		posi[0] = {0,0};
		for (int i = 1; i < k+1; ++i){
			int x, y;
			cin >> posi[i].first >> posi[i].second;
		}
		int max = 0, punt_act = 0, dist = -1;
		bool fin = false;
		int i = 0;
		while(i < k and not fin){
			dist = bfs(n, m, posi[i], posi[i+1]);
			if (dist == -1) fin = true;
			else{
				punt_act += w;
				punt_act -= l*dist;
				if (punt_act > max) max = punt_act;
			}
			++i;
		}
		cout << max << endl;
	}
}