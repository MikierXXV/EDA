#include <iostream>
#include <vector>
using namespace std;

const int ADN[4] = {'A','C','G','T'};

void escriu(const vector<char>& v){
	for (int i = 0; i < int(v.size()); ++i){
		cout << v[i]; 
	}
	cout << endl;
}

void backtrack(int i, vector<char>& sol, int n){
	if (i == n) escriu(sol);
	else{
		for (int j = 0; j < 4; ++j){
			sol[i] = ADN[j];
			backtrack(i+1, sol, n);
		}
	}
}

int main(){

	int n;
	cin >> n;
	vector<char> v(n);
	backtrack(0, v, n);
}