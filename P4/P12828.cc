#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& sol, int n){
	bool primer = true;
	for (int i = 0; i < n; ++i){
		if (primer) primer = false;
		else cout << ' ';
		cout << sol[i];
	}
	cout << endl;
}


void back_track(int i, vector<int>& sol, int n){
	if(i == n){
		escriu(sol, n);
	}
	else{
		sol[i] = 0;
		back_track(i+1, sol, n);
		sol[i] = 1;
		back_track(i+1, sol, n);
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> sol(n);
	back_track(0, sol, n);
}