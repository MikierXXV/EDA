#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& sol, int n){
	bool primer = true;
	cout << '(';
	for (int i = 0; i < n; ++i){
		if (primer) primer = false;
		else cout << ",";
		cout << sol[i];
	}
	cout << ')' << endl;
}


void back_track(vector<int>& sol, vector<bool>& usat, int n, int i){
	if(i == n){
		escriu(sol, n);
	}
	else{
		for(int j = 0; j < n; ++j){
			if (not usat[j]){
				sol[i] = j+1;
				usat[j] = true;
				back_track(sol, usat, n, i+1);
				usat[j] = false;
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> sol(n);
	vector<bool> usat(n, false);
	back_track(sol, usat, n, 0);
}