#include <iostream>
#include <vector>
#include <string>
using namespace std;

void escriu_sol(const vector<string>& vs, const vector<int>& v, int n){
	cout << '(';
	for (int i = 0; i < n; ++i){
		if (i == 0) cout << vs[v[i]];
		else {
			cout << "," << vs[v[i]];
		} 
	}
	cout << ')' << endl;;
}

void permutacions(int n, const vector<string>& vs,  int i, vector<int>& v, vector<bool>& vis){

	if (i == n) escriu_sol(vs, v, n);
	else {
		for (int j = 0; j < n; ++j){
			if(not vis[j]){
				vis[j] = true;
				v[i] = j;
				permutacions(n, vs, i+1, v, vis);
				vis[j] = false;
			}
		}
	}
}

int main(){

	int n;
	cin >> n;
	vector<string> vs(n);
	for (int i = 0; i < n; ++i) cin >> vs[i];
	vector<int> sol(n);  //pos del string en vs
	vector<bool> vis(n, false);

	permutacions(n, vs, 0, sol, vis);

}