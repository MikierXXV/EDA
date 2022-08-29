#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tablero;
typedef pair<int, int> Pos;

const vector<Pos> dirs = {{-2,-1}, {-1,-2}, {2,1}, {1,2}, {2,-1}, {1, -2}, {-2,1}, {-1,2}};

bool pos_ok(Pos seg, int n, int m){
	return seg.first >= 0 and seg.first < n and seg.second >= 0 and seg.second < m;
}

int bfs()

int main(){

	int f, c;
	while(cin >> f >> c){
		Tablero t(n, vector<char>(m));
		bool pastan = false;
		for (int i = 0; i < f; ++i){
			for (int j = 0; j < c; ++j){
				cin >> t[i][j];
				if (t[i][j] == 'p') pastan = true;
			}
		}
		int x, y;
		cin >> x >> y;
		Pos ini = {x-1,y-1};
		if (not pastan) cout << "no" << endl;
		else{
			int res = bfs(t, ini, f, c);
			if(res > -1) cout << "res" << endl;
			else cout << "no" << endl;
		}
	}
}