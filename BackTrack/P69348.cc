#include <iostream>
#include <vector>
using namespace std;

void escriu_sol(const vector<int>& v, int n){
	cout << '(';
	for (int i = 0; i < n; ++i){
		if (i == 0) cout << v[i];
		else {
			cout << ", " << v[i];
		} 
	}
	cout << ')' << endl;;
}

void dunaena(int n, int i, vector<int>& v, vector<bool>& vis){

	if (i == n) escriu_sol(v,n);
	else {
		for (int j = 0; j < n; ++j){
			if(not vis[j]){
				vis[j] = true;
				v[i] = j+1;
				dunaena(n, i+1, v, vis);
				vis[j] = false;
			}
		}
	}
}

int main(){

	int n;
	cin >> n;
	vector<int> sol(n);
	vector<bool> vis(n, false);

	dunaena(n, 0, sol, vis);
}