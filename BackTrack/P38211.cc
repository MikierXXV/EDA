#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Fila;
typedef vector<Fila> Matriu;

typedef vector<bool> VB;


int diag1(int n, int f, int c){
	return n-c-1+f;
}

int diag2(int f, int c){
	return f+c;
}

void escribir(const Matriu& m, int n){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j) cout << m[i][j];
		cout << endl;
	}
}

bool reinas(Matriu& m, VB& col, VB& d1, VB& d2, int i, int n){
	if (i == n) return true;
	else {
		for(int j = 0; j < n; ++j){
			if (not col[j] and not d1[diag1(n,i,j)] and not d2[diag2(i,j)]){
				m[i][j] = 'Q';

				col[j] = true;
				d1[diag1(n,i,j)] = true;
				d2[diag2(i,j)] = true;

				bool b = reinas(m, col, d1, d2, i+1, n);
				if(b) return b;

				m[i][j] = '.';

				col[j] = false;
				d1[diag1(n,i,j)] = false;
				d2[diag2(i,j)] = false; 
			}

		}
		return false;
	}
}


int main (){

	int n;
	cin >> n;
	Matriu m(n, Fila(n, '.'));

	VB col(n, false);
	VB d1(2*n-1, false);
	VB d2(2*n-1, false);

	if (reinas(m, col, d1, d2, 0, n)) escribir(m, n);
	else cout << "NO SOLUTION" << endl;

}