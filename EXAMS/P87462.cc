#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> tablero;
typedef pair<int,int> pos;

//movimientos pacman
const int px[4]={-1,0,1,0};
const int py[4]={0,1,0,-1};
const int fx[8]={-1,-1,0,1,1,1,0,-1};
const int fy[8]={0,1,1,1,0,-1,-1,-1};

bool bfs(tablero& t, int f, int c){
	queue<pos> q;
	q.push(pos(f,c));
	t[f][c] = 'X';
	while(not q.empty()){
		pos p = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int x = p.first + px[i];
			int y = p.second + py[i];
			if(t[x][y] == 'B') return true;
			else if (t[x][y] != 'X'){
				q.push(pos(x,y));
				t[x][y] = 'X';
			}
		}
	}
	return false;
}

int main(){

	int n, m;
	while(cin >> n >> m){
		tablero t(n, vector<char>(m));
		queue<pos> qF;
		int f, c;
		bool bolet = false;
		//leer tablero añado posiciones del pacman y fantasmas en respectivas colas
		for (int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> t[i][j];
				if(t[i][j] == 'P'){
					f = i;
					c = j;
				}
				else if(t[i][j] == 'F'){
					qF.push(pos(i,j));
				}
				else if (t[i][j] == 'B'){
					bolet = true;
				}
			}
		}
		if (bolet){
			while(not qF.empty()){
				pos p = qF.front();
				qF.pop();
				for (int i = 0; i < 8; ++i){
					int x = p.first + fx[i];
					int y = p.second + fy[i];
					t[x][y] = 'X';
				}
			}
			bool trobat = false;
			if(t[f][c] != 'X') trobat = bfs(t,f,c);
			if(trobat) cout << "si" << endl;
			else cout << "no" << endl;	
		}
		else cout << "no" << endl;
	}
}