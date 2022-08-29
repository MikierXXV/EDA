#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> matrix;


int diago1(int i, int j){
	return i+j;
}

int diago2(int i, int j, int n){
	return n-j-1+i;
}

void escriu(const matrix& mat, int n){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j) cout << mat[i][j];
		cout << endl;
	}
	cout << endl;
}

void n_reinas(int i, int n, matrix& mat, vector<bool>& diag1, vector<bool>& diag2, vector<bool>& col, int& cont){
	if (i == n) ++cont;
	else{
		for (int j = 0; j < n; ++j){
			if (not diag1[diago1(i, j)] and not diag2[diago2(i, j, n)] and not col[j]){
				mat[i][j] = 'Q';
				col[j] = true;
				diag1[diago1(i, j)] = true;
				diag2[diago2(i, j, n)] = true;
				n_reinas(i+1, n, mat, diag1, diag2, col, cont);
				mat[i][j] = '.';
				col[j] = false;
				diag1[diago1(i, j)] = false;
				diag2[diago2(i, j, n)] = false;

			}
		}
	}
}




int main() {
	int n, cont = 0;
	cin >> n;
	matrix mat(n, vector<char>(n, '.'));

	//pos vector = i, contenido = j
	vector<bool> diag1(2*n-1, false);	//i+j;
	vector<bool> diag2(2*n-1, false);	//n-j-1+i;	
	vector<bool> col(n, false);
	
	n_reinas(0, n, mat, diag1, diag2, col, cont);
	cout << cont << endl;

}