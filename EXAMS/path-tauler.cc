#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef vector<vector<int>> Tablero;
typedef pair<int, int> Pos;
typedef pair<int, Pos> dist_pos;

const vector<Pos> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

const int infinite = INT_MAX;

bool perfieria(Pos p, int n){
	return p.first == 0 or p.second == 0 or p.first == n-1 or p.second == n-1;
}

int cost_min(const Tablero& t, int n){
	Pos centro = {n/2, n/2};
	Tablero dist(n, vector<int>(n, infinite));

	priority_queue<dist_pos, vector<dist_pos>, greater<dist_pos>> pq;
	dist[centro.first][centro.second] = t[centro.first][centro.second];
	pq.push({dist[centro.first][centro.second], centro});

	while(not pq.empty()){
		Pos act = pq.top().second;
		pq.pop();

		if(perfieria(act, n)) return dist[act.first][act.second];
		for(int i = 0; i < 4; ++i){
			Pos seg;
			seg.first = act.first + dirs[i].first;
			seg.second = act.second + dirs[i].second;
			if(dist[seg.first][seg.second] > dist[act.first][act.second] + t[seg.first][seg.second]){
				dist[seg.first][seg.second] = dist[act.first][act.second] + t[seg.first][seg.second];
				pq.push({dist[seg.first][seg.second], seg});
			}
		}
	}
}


int main(){
	int n;
	while(cin >> n){
		Tablero t(n, vector<int>(n));
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j) cin >> t[i][j];
		}
		cout << cost_min(t, n) << endl;
	}
}