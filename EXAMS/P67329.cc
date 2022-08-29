#include <iostream>
#include <vector>
using namespace std;


const int ADN[4] = {'A','C','G','T'};

void escriu(const vector<char>& sol){
	int n = sol.size();
	for (int i = 0; i < n; ++i){
		cout << sol[i]; 
	}
	cout << endl;
}

void back_tack(int i, vector<char>& sol, int n){
	if(i == n) escriu(sol);
	else{
		for(int j = 0; j < 4; ++j){
			sol[i] = ADN[j];
			back_tack(i+1, sol, n);
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<char> sol(n);
	back_tack(0, sol, n);
}