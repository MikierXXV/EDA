#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<string> VS;
typedef vector<VS> MS;
typedef vector<vector<int>> MI;
typedef pair<int, int> Pos;

const int X[4] = {1, 0, -1, 0};
const int Y[4] = {0, 1, 0, -1};

bool pos_ok(const MS& M, int i, int j) {
  	return i >= 0 and i < int(M.size()) and j >= 0 and j < int(M[0].size()) and M[i][j] != "*";
}

int bfs(const MS& M, Pos& orig, Pos& dest) {
  	int n = M.size();
  	int m = M[0].size();
  	MI dist(n,vector<int>(m,-1));
  	queue<Pos> Q;

  	Q.push(orig);
  	dist[orig.first][orig.second] = 0;

  	while (not Q.empty()) {
    	Pos u = Q.front();
    	Q.pop();
    	if (u == dest) return dist[u.first][u.second];
    	for (int i = 0; i < 4; ++i) {
    		int x = u.first + X[i];
    		int y = u.second + Y[i];
      		Pos v = {x, y};
      		if (pos_ok(M, x, y) and dist[x][y] == -1) {
				Q.push(v);
				dist[x][y] = dist[u.first][u.second] + 1;
      		}
    	}
  	}
    return -1;
}

Pos buscar_posicio(const MS& M, const string& s){
  	for (int i = 0; i < M.size(); ++i){
    	for (int j = 0; j < M[0].size(); ++j){
      		if (M[i][j] == s) return {i,j};
    	}
  	}
  	return {-1,-1};  
}

int main() {
  	int n, m;
  	while (cin >> n >> m) {
    	MS M(n,VS(m));
    	for (int i = 0; i < n; ++i){
      		for (int j = 0; j < m; ++j)
				cin >> M[i][j];
    	}
    	int p;
    	cin >> p;
    	VS paraules(p);
    	for (int i = 0; i < p; ++i) cin >> paraules[i];

    	vector<Pos> posicions(p+1);
      	posicions[0] = {0,0};
    	for (int i = 0; i < p; ++i) 
      		posicions[i+1] = buscar_posicio(M,paraules[i]);

    	int total = 0;
    	bool ok = true;
    	for (int i = 0; ok and i < posicions.size() - 1; ++i) {
      		int d = bfs(M, posicions[i], posicions[i+1]);
      		if (d == -1) ok = false;
      		else total += d;
    	}
    	if (ok) cout << (total + p) << endl;
    	else cout << "impossible" << endl;
  	}
}
