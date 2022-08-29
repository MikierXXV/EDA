#include <iostream>
#include <vector>
using namespace std;

void escriu_sol(const vector<int>& v, int n){
	for (int i = 0; i < n; ++i){
		if (i == 0) cout << v[i];
		else {
			cout << ' ' << v[i];
		} 
	}
}

void zerouns(int n, int i, int u, vector<int>& v, int nu){
	if (nu > u) return;
	if (n-u < i-nu) return;
	if (i == n) {
		escriu_sol(v, n);
	}
	else{
		v[i] = 0;
		zerouns(n, i+1, u, v, nu);
		v[i] = 1;
		zerouns(n, i+1, u, v, ++nu);
	}

}

int main(){

	int n;
	cin >> n;
	vector<int> sol(n);

	zerouns(n, 0, 0, sol, 0);
}