#include <iostream>
#include <vector>
using namespace std;


void escribir(const vector<int>& v, const vector<bool>& sol, int n){
	cout << "{";
	bool primer = true;
	for (int i = 0; i < n; ++i){
		if (sol[i]){
			if (not primer) cout << ",";
			else primer = false;
			cout << v[i];
		}
	}
	cout << "}" << endl;
}
void sumaigual(vector<int>& v, int i, int s, int n, vector<bool>& sol, int sum_act){
	if (i == n){
		if (s == sum_act) escribir(v, sol, n);
	}
	else {
		sol[i] = false;
		sumaigual(v, i+1, s, n, sol, sum_act);

		sol[i] = true;
		sumaigual(v, i+1, s, n, sol, sum_act+v[i]);
	}
}
int main(){

	int s, n;
	cin >> s >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<bool> sol(n);
	sumaigual(v, 0, s, n, sol, 0);
}