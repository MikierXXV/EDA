#include <iostream>
#include <vector>
#include <algorithm>
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
bool sumaigual(vector<int>& v, int i, int s, int n, vector<bool>& sol, int sum_act){
	if (i == n){
		if (s == sum_act){
			escribir(v, sol, n);
			return true;
		}
		else return false; 
	}
	else {
		sol[i] = true;
		bool b = sumaigual(v, i+1, s, n, sol, sum_act+v[i]);
		if (not b){
			sol[i] = false;
			return sumaigual(v, i+1, s, n, sol, sum_act);
		}
		else return true;
	}
}

bool comp(int a, int b){
	return a > b;
}

int main(){

	int s, n;
	cin >> s >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end(), comp);

	vector<bool> sol(n);
	if (not sumaigual(v, 0, s, n, sol, 0)) cout << "no solution" << endl;;
}