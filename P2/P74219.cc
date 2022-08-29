#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long>> Matriu;
const Matriu F({{1,1},{1,0}});

void multiplica(const Matriu& m1, const Matriu& m2, Matriu& r, int mod){
	r = Matriu(m1.size(), vector<long> (m2[0].size(),0));
	for (int i = 0; i < m1.size(); ++i){
		for (int j = 0; j < m2[0].size(); ++j){
			for (int k = 0; k < m2.size(); ++k) r[i][j] += m1[i][k] * m2[k][j];
				r[i][j] %= mod;
		}
	}
} 


void potMatrix(const Matriu& m, int n, int mod, Matriu& r){
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
	else if (n%2 == 0){
		Matriu aux(2, vector<long> (2));
		potMatrix(m, n/2, mod, aux);
		multiplica(aux, aux, r, mod);
	}
	else {
		Matriu aux(2, vector<long> (2));
		potMatrix(m, n-1, mod, aux);
		multiplica(m, aux, r, mod);	
	}

}



long fibonacci(int n, long m){
	if (n < 2) return n;
	Matriu aux(2, vector<long> (2));
	potMatrix(F, n, m, aux);
	return aux[0][1];
}


int main (){
	int n;
	long m;
	while (cin >> n >> m){
		cout << fibonacci(n, m) << endl;
	}
}