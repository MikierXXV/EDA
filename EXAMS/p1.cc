#include <iostream>
#include <vector>
using namespace std;


typedef vector<vector<char>> Matrix;

int backtrack(int i, Matrix& sol, int n, int m, int j, int numlols){
	if (i == n) return numlols;
	else{
		sol[i][j] = 'L';

		//como o no genera se queda con iniciales y l es la que genera
		int num_act = 0;

		//horizontal
		if(j >= 2 and sol[i][j-2] == 'L' and sol[i][j-1] == 'O') ++num_act;
		//vertical
		if(i >= 2 and sol[i-2][j] == 'L' and sol[i-1][j] == 'O') ++num_act;
		//diagonal 1
		if(i >= 2 and j >= 2 and sol[i-2][j-2] == 'L' and sol[i-1][j-1] == 'O') ++num_act;
		//diagonal2
		if(i >= 2 and j <= m-2 and sol[i-2][j+2] == 'L' and sol[i-1][j+1] == 'O') ++num_act;

		int ni, nj;

		//recorrrer las posiciones de la matriz por filas y columnas
		if(j == m-1){
			ni = i+1;
			nj = 0;
		}
		else {
			ni = i;
			nj = j+1;
		}
		//numero maximo de lols poninendo l
		int num_l = backtrack(ni, sol, n, m, nj, num_act + numlols);

		//i j posicion actual, ni nj posicion llamada recursiva
		sol[i][j] = 'O';
		int num_o = backtrack(ni, sol, n, m, nj, numlols);

		return max(num_l, num_o);
	}
}

int main(){
	int n, m;
	while (cin >> n >> m){
		Matrix mat(n, vector<char>(m));
		cout << backtrack(0, mat, n, m, 0, 0) << endl;
	}
}