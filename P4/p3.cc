#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tablero;

int diag1(int n, int f, int c){
	return n-c-1+f;
}

int diag2(int n, int f, int c){
	return f+c;
}

void escriu(const Tablero& m, int n){
	for(int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << m[i][j];
		}
		cout << endl;
	}
}

bool queens(Tablero& m, vector<bool>& col, vector<bool>& d1, vector<bool>& d2, int n, int i){
	if (i == n){
		escriu(m, n);
		return true;
	}
	else{
		for (int j = 0; j < n; ++j){
			int di1 = diag1(n, i, j);
			int di2 = diag2(n, i, j);
			if (not col[j] and not d1[di1] and not d2[di2]){
				m[i][j] = 'Q';
				col[j] = true;
				d1[di1] = true;
				d2[di2] = true;
				if (queens(m, col, d1, d2, n, i+1)) return true;
				m[i][j] = '.';
				col[j] = false;
				d1[di1] = false;
				d2[di2] = false;
			}
		}
	}
	return false;
}

int main(){
	int n;
	cin >> n;
	Tablero m(n, vector<char>(n, '.'));
	vector<bool> col(n, false);
	vector<bool> d1(2*n-1, false);
	vector<bool> d2(2*n-1, false);
	bool trobat = queens(m, col, d1, d2, n, 0);
	if (not trobat) cout << "NO SOLUTION" << endl; 
}