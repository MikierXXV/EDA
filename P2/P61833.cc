#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;

void multiplica(const matrix& m, const matrix& m1, matrix& res, int mod){
	res = matrix(m.size(), vector<int>(m1[0].size(),0));
	for (int i = 0; i < m.size(); ++i){
		for (int j = 0; j < m1[0].size(); ++j){
			for (int k = 0; k < m1.size(); ++k){
				res[i][j] += m[i][k] * m1[k][j];
			}
			res[i][j] %= mod;
		}
	}
}

void potMatrix(const matrix& m, int n, int mod, matrix& r){
	if (n == 0){
		r[0][0] = r[1][1] = 1;
		r[0][1] = r[1][0] = 0;
	}
	else if (n == 1){
		r[0][0] = m[0][0] % mod;
		r[0][1] = m[0][1] % mod;
		r[1][0] = m[1][0] % mod;
		r[1][1] = m[1][1] % mod;
	}
	else {
		if (n%2 == 0){
			matrix aux(2, vector<int>(2));
			potMatrix(m, n/2, mod, aux);
			multiplica(aux, aux, r, mod);
		}
		else{
			matrix aux(2, vector<int>(2));
			potMatrix(m, n-1, mod, aux);
			multiplica(m, aux, r, mod);
		}
	}

}

int main(){
	matrix m(2, vector<int>(2));
	int n, mod;
	while (cin >> m[0][0] >> m[0][1] >> m[1][0] >> m[1][1] >> n >> mod){
		matrix r(2, vector<int>(2));
		potMatrix(m, n, mod, r);
		cout << r[0][0] << ' ' << r[0][1] << endl;
		cout << r[1][0] << ' ' << r[1][1] << endl;
		cout << "----------" << endl;
	}
}