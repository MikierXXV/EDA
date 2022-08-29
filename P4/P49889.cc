#include <iostream>
#include <vector>
using namespace std;

void escribe(const vector<char>& sol){
	int n = sol.size();
	for (int i = 0; i < n; ++i) cout << sol[i];
	cout << endl;
}

void back_track(int i, int n, const vector<char>& cons, const vector<char>& voca, 
	vector<bool>& cons_vis, vector<bool>& voca_vis, vector<char>& sol){
	if (i == n){
		escribe(sol);
	}
	else{

	}
}


int main(){

	int n;
	cin >> n;
	vector<char> cons(n);
	vector<bool> cons_vis(n, false);
	vector<char> voca(n);
	vector<bool> voca_vis(n, false);
	vector<char> sol();
	for (int i = 0; i < n; ++i) cin >> cons[i];
	for (int i = 0; i < n; ++i) cin >> voca[i];

	back_track(0, n, cons, vocal, cons_vis, voca_vis, sol);

}