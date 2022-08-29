#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef vector<vector<char>> Tablero;
typedef vector<vector<bool>> Mapa;
typedef pair<int,int> pos;

const int xb[4]={1,-1,1,-1};
const int yb[4]={1,1,-1,-1};
const int xc[8]={-2,-1,1,2,2,1,-1,-2};
const int yc[8]={1,2,2,1,-1,-2,-2,-1};

bool pos_ok(int x, int y, Tablero& t){
	return x >= 0 and y >= 0 and x < t.size() and y < t[0].size();
}

int bfs_b(Tablero& t, Mapa& visitB, queue<pos>& q){
	int suma = 0;
	while(not q.empty()){
		pos p = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int x = p.first + xb[i];
			int y = p.second + yb[i];
			if(pos_ok(x,y,t) and t[x][y] != 'T' and not visitB[x][y]){
				visitB[x][y] = true;
				q.push(pos(x,y));
				if(t[x][y] >= '0' and t[x][y] <= '9') {
					suma += (t[x][y] - '0');
					t[x][y] = '.';
				}
			}
		}
	}
	return suma;
}

int bfs_c(Tablero& t, Mapa& visitC,queue<pos>& q){
	int suma = 0;
	while(not q.empty()){
		pos p = q.front();
		//cout << "entro while " << p.first << ',' << p.second << endl;
		q.pop();
		for(int i = 0; i < 8; ++i){
			int x = p.first + xc[i];
			int y = p.second + yc[i];
			if(pos_ok(x,y,t) and t[x][y] != 'T' and not visitC[x][y]){
				visitC[x][y] = true;
				q.push(pos(x,y));
				if(t[x][y] >= '0' and t[x][y] <= '9') {
					suma += (t[x][y] - '0');
					t[x][y] = '.';
				}
			}
		}
	}
	return suma;
}


int main(){

	int n, m;
	while (cin >> n >> m) {
		Tablero t(n,vector<char>(m));
		Mapa visitB(n,vector<bool>(m,false));
		Mapa visitC(n,vector<bool>(m,false));
		queue<pos> qb, qc;
		
		for(int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> t[i][j];
				if(t[i][j]=='B'){
					qb.push(pos(i,j));
					visitB[i][j] = true;
					//cout << "pos: " << i << ',' << j << endl;
				}
				else if(t[i][j]=='K'){
					qc.push(pos(i,j));
					//cout << "pos: " << i << ',' << j << endl;
					visitC[i][j] = true;
				}
			}
		}
		int suma = bfs_b(t,visitB,qb);
		suma += bfs_c(t,visitC,qc);
		cout << suma << endl;
	}

}

