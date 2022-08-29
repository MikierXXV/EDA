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



int reinas(Matriu& m, VB& col, VB& d1, VB& d2, int i, int n, int suma){
	if (i == n) return suma;
	else {
		for(int j = 0; j < n; ++j){
			if (not col[j] and not d1[diag1(n,i,j)] and not d2[diag2(i,j)]){
				m[i][j] = 'Q';
				++suma;
				col[j] = true;
				d1[diag1(n,i,j)] = true;
				d2[diag2(i,j)] = true;

				reinas(m, col, d1, d2, i+1, n, suma);

				m[i][j] = '.';

				col[j] = false;
				d1[diag1(n,i,j)] = false;
				d2[diag2(i,j)] = false; 
			}

		}

	}
}


int main (){

	int n, sum = 0;
	cin >> n;
	Matriu m(n, Fila(n, '.'));

	VB col(n, false);
	VB d1(2*n-1, false);
	VB d2(2*n-1, false);

	int suma = reinas(m, col, d1, d2, 0, n, sum);
	cout << suma << endl;


}