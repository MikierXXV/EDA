#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


typedef vector<vector<char>> Tablero;
typedef vector<vector<int>> Dist;
typedef pair<int, int> Parint;

const vector<Parint> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
const int infinite = INT_MAX;

bool pos_ok(Parint p, int n, int m){
	return p.first >= 0 and p.second >= 0 and p.first < n and p.second < m;
}

Parint bfs(Tablero& t, int n, int m){
	Dist dist(n, vector<int>(m, infinite));
	Dist pers(n, vector<int>(m, -1));

	queue<Parint> q;

	q.push({0,0});
	dist[0][0] = 0;
	pers[0][0] = 0;
	if (t[0][0] == 'P') ++pers[0][0];

	while(not q.empty()){
		Parint act = q.front();
		q.pop();
		if(t[act.first][act.second] == 'T') return {dist[act.first][act.second], pers[act.first][act.second]};
		for (int i = 0; i < 4; ++i){
			Parint seg;
			seg.first = act.first + dirs[i].first;
			seg.second = act.second + dirs[i].second;
			if(pos_ok(seg, n, m) and t[seg.first][seg.second] != '#'){
				int d = dist[act.first][act.second];
				int np = pers[act.first][act.second];
				if (t[seg.first][seg.second] == 'P') ++np;
				if (dist[seg.first][seg.second] == infinite){ //no visitada
					q.push(seg);
					dist[seg.first][seg.second] = d+1;
					pers[seg.first][seg.second] = np;
				}
				//actualizar numero de personas al maximo
				else if(dist[seg.first][seg.second] == d+1 and pers[seg.first][seg.second] < np){
					pers[seg.first][seg.second] = np;
				}
			}
		}

	}
	return {-1,-1};

}

int main(){
	int n, m;
	while(cin >> n >> m){
		Tablero t(n, vector<char>(m));
		bool esta = false;
		for (int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> t[i][j];
				if(t[i][j] == 'T') esta = true;
			}
		}
		if (not esta) cout << "El telecos ha fugit." << endl;
		else{
			Parint res = bfs(t, n, m); //res.first distancia minima, .second numero max de personas
			if(res.first == -1) cout << "El telecos esta amagat." << endl;
			else cout << res.first  << ' ' << res.second << endl;
		}
	}
}