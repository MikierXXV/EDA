#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<string>& vs, const vector<int>& sol, int n){
	cout << '(';
	for (int i = 0; i < n; ++i){
		if (i == 0) cout << vs[sol[i]];
		else {
			cout << "," << vs[sol[i]];
		}
	}
	cout << ')' << endl;
}


void back_track(const vector<string>& vs, vector<int>& sol, vector<bool>& usat, int n, int i){
	if(i == n){
		escriu(vs, sol, n);
	}
	else{
		for(int j = 0; j < n; ++j){
			if (not usat[j]){
				sol[i] = j;
				usat[j] = true;
				back_track(vs, sol, usat, n, i+1);
				usat[j] = false;
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<string> vs(n);
	for (int i = 0; i < n; ++i) cin >> vs[i];
	vector<int> sol(n);
	vector<bool> usat(n, false);
	back_track(vs, sol, usat, n, 0);
}