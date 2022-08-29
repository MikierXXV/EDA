#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Mapa;

const int X[8] = {1,1,0,-1,-1,-1,0,1};
const int Y[8] = {0,-1,-1,-1,0,1,1,1};

void escriu(const Mapa& m){
	int n = m.size();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cout << m[i][j];
		cout << endl;
	}
	cout << "----------" << endl;
}

bool pos_ok(int n, int x, int y){
	return x >= 0 and x < n.size() and y >= 0 and y < n.size();
}

bool amenaza(const Mapa& m, int x, int y){
	for(int i = 0; i < 8; ++i){
		int x_sig = x + X[i];
		int y_sig = y + Y[i];
		if (m[x_sig][y_sig] == 'K' and pos_ok(m.size),x_sig,y_sig) return true;
	}
}	return false;

void backtrack(Mapa& m, int pos, int n, int r, int nr){
	if(nr == r) escriu(m);
	else if(pos < n*n){
		//consultar posicion
		int i = pos/n;
		int j = pos%n;
		//ponemos un rei
		if(m[i][j] == '.' and not amenaza(m,i,j)){
			m[i][j] = 'K';
			backtrack(m,pos+1,n,r,nr+1);
		}
		//no poner rei o no puedo ponerlo
		m[i][j] = '.';
		backtrack(m,pos+1,n,r,nr);
	} 
}

int main(){
	int n, r;
	cin >> n >> r;
	Mapa m(n, vector<char>(n,'.'));
	backtrack(m,0,n,r,0);
}