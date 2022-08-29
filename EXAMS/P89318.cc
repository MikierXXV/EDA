#include <iostream>
#include <vector>
using namespace std;


void escriu(const vector<char>& sol){
	int n = sol.size();
	for (int i = 0; i < n; ++i){
		cout << sol[i]; 
	}
	cout << endl;
}

void back_track(int i, vector<char>& sol, vector<bool>& usat, int n){
	if(i == n) escriu(sol);
	else{
		for(int j = 0; j < sol.size(); ++j){
			if(not usat[j] and (i == 0 or sol[i-1]+1 != 'a'+j)){
				sol[i] = 'a'+j;
				usat[j] = true;
				back_track(i+1,sol,usat,n);
				usat[j] = false;
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<char> sol(n);
	vector<bool> usat(n, false);
	back_track(0, sol, usat, n);
}