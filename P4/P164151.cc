#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> F;
typedef vector<bool> VB;
typedef vector<F> Matrix;

int diag1(int n, int f, int c){
	return n-c-1+f;
}

int diag2(int f, int c){
	return f+c;
}


int n_reinas(int i, int n, Matrix& M, VB& col, VB& d1, VB& d2, int& cont){
	if (i == n) return cont;
	else{
		for (int j = 0; j < n; ++j){
			if (not col[j] and not d1[diag1(n, i, j)] and not d2[diag2(i, j)]){
				M[i][j] = 'Q';
				col[j] = true;
				d1[diag1(n, i, j)] = true;
				d2[diag2(i, j)] = true;
				

				n_reinas(i+1, n, M, col, d1, d2, ++cont);
				

				M[i][j] = '.';
				col[j] = false;
				d1[diag1(n, i, j)] = false;
				d2[diag2(i, j)] = false;
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	Matrix M(n, F(n, '.'));
	VB col(n, false);
	VB d1(2*n-1, false);
	VB d2(2*n-1, false);
	int cont = 0;
	cout << n_reinas(0, n, M, col, d1, d2, cont);

}
