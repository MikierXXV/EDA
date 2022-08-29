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

void zerouns(int n, int i, vector<int>& v){
	if (i == n) {
		escriu_sol(v, n);
	}
	else{
		v[i] = 0;
		zerouns(n, i+1, v);
		v[i] = 1;
		zerouns(n, i+1, v);
	}

}

int main(){

	int n;
	cin >> n;
	vector<int> sol(n);

	zerouns(n, 0, sol);
}