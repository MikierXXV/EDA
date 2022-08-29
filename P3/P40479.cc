#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<char>> Matrix;
typedef pair<int, int> pos;


const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};



void dfs(Matrix& mat, char color, int f, int c){
	stack<pos> p;
	p.push({f,c});
	while (not p.empty()){
		pos act = p.top();
		p.pop();
		for (int i = 0; i < 4; ++i){
			int x = act.first + X[i];
			int y = act.second + Y[i];
			if (mat[x][y] == '.'){
				p.push({x,y});
				mat[x][y] = color;
			}
		}
	}
}

void pinta_mat(Matrix& mat, int n, int m){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (mat[i][j] != '#' and mat[i][j] != '.')
				dfs(mat, mat[i][j], i, j);
		}
	}
}


int main(){
	int n, m;
	while (cin >> n >> m){
		Matrix mat(n, vector<char>(m));
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j) cin >> mat[i][j];
		}

		pinta_mat(mat, n, m);

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cout << mat[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}