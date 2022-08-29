#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> tablero;
typedef pair<int,int> pos;

const int X[4]={-1,0,1,0};
const int Y[4]={0,1,0,-1};

bool pos_ok(int x, int y, tablero& t){
	return x >= 0 and y >= 0 and x < t.size() and y < t[0].size();
}

bool dfs(tablero& t, const pos& act, const pos& fin){
	if(act == fin) return true;
	else{
		for (int i = 0; i < 4; ++i){
			int x = act.first + X[i];
			int y = act.second + Y[i];
			if(pos_ok(x,y,t) and t[x][y] != 'X'){
				t[x][y] = 'X';
				if(dfs(t,{x,y},fin)) return true;
			} 
		}
		return false;
	}
} 
int main(){
	int n, m;
	while (cin >> n >> m){
		int fi, ci, ff, cf;
		tablero t(n,vector<char>(m));
		queue<pos> qm;
		for(int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> t[i][j];
				if (t[i][j] == 'I'){
					fi = i;
					ci = j;
				}
				else if(t[i][j] == 'F'){
					ff = i;
					cf = j;
				}
				else if(t[i][j] == 'M'){
					qm.push(pos(i,j));
				}
			}
		}
		pos ini = pos(fi,ci);
		pos fin = pos(ff,cf);
		while(not qm.empty()){
			pos p = qm.front();
			qm.pop();
			for (int i = 0; i < 4; ++i){
				int x = p.first + X[i];
				int y = p.second + Y[i];
				if(pos_ok(x,y,t)) t[x][y] = 'X';
			}

		}
		if (dfs(t, ini, fin)) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}