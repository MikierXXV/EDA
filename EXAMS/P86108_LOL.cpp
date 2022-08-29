#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Mapa;

int back(int i, int j, Mapa& sol, int num, int n, int m) {
	if (i == n) return num;
	//Ponemos una 'L'
	sol[i][j] = 'L';
	int num_lol = 0;
	
	//hay LOL en la columna
	if (i >= 2 and sol[i-2][j] == 'L' and sol[i-1][j] == 'O') ++num_lol;
	//hay LOL en la fila
	if (j >= 2 and sol[i][j-2] == 'L' and sol[i][j-1] == 'O') ++num_lol;
	//hay LOL en la diagonal 1 (izq-der)
	if (i >= 2 and j >= 2 and sol[i-2][j-2] == 'L' and sol[i-1][j-1] == 'O') ++num_lol;
	//hay LOL en la diagonal 2 (der-izq)
	if (i >= 2 and j + 2 < m and sol[i-2][j+2] == 'L' and sol[i-1][j+1] == 'O') ++num_lol;
	
	int ni = i, nj = j;
	if (j == m-1) {
		++ni;
		nj = 0;
	}
	else ++nj;
	
	int num_l = back(ni, nj, sol, num + num_lol, n, m);
	//num_l = numero maximo de lol's poniendo L en la posicion i, j
	
	sol[i][j] = 'O';
	int num_o = back(ni, nj, sol, num, n, m);
	//num_o = numero maximo de lol's poniendo O en la posicion i, j
	
	return max(num_l, num_o);
}

int main () {
	int n, m;
	while (cin >> n >> m) {
		Mapa sol(n, vector<char>(m));
		cout << back(0, 0, sol, 0, n, m) << endl;
	}
}
