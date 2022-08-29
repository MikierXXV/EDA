#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriu;

const Matriu X({{1,1},{1,0}});

Matriu mult(const Matriu& A, const Matriu& B, int m){
	Matriu C(2,vector<int>(2));
	for (int i = 0; i < A.size(); ++i){
		for(int j = 0; j < A[0].size(); ++j){
			for(int k = 0; k < B.size(); ++k){
				C[i][j] += A[i][k] * B[k][j];
			}
			C[i][j] %= m;
		}
	}
	return C;
}

void pow_matrix(const Matriu& X, Matriu& res, int n , int m){
	if(n == 0){
		res[0][0] = res[1][1] = 1;
		res[0][1] = res[1][0] = 0;
	}
	else{
		Matriu aux(2, vector<int>(2));
		pow_matrix(X,aux,n/2,m);
		res = mult(aux, aux, m);
		if(n%2 != 0) res = mult(res, X, m);
	}

}

int fibonacci(int n, int m){
	if(n < 2) return n;
	Matriu aux(2, vector<int>(2));
	pow_matrix(X, aux, n, m);
	return aux[0][1];
}

int main(){
	int n, m;
	while(cin >> n >> m){
		cout << fibonacci(n, m) << endl;
	}

}