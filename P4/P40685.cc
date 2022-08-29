#include <iostream>
#include <vector>
using namespace std;


void escribe(const vector<int>& v, vector<bool>& sol, int n){
	cout << "{";
	bool primer = true;
	for (int i = 0; i < n; ++i) {
		if (sol[i]){
			if (not primer) cout << ",";
			else primer = false;
			cout << v[i];
		}
	}
	cout << "}" << endl;
}


void back_track(int i, int n, int s, vector<int>& v, vector<bool>& sol, int s_act){
	if (i == n){
		if (s == s_act) escribe(v, sol, n);
	} 
	else{
		sol[i] = false;
		back_track(i+1, n, s, v, sol, s_act);

		sol[i] = true;
		back_track(i+1, n, s, v, sol, s_act+v[i]);
	}
}


int main() {

	int s, n;
	cin >> s >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	vector<bool> sol(n, false);

	back_track(0, n, s, v, sol, 0);
}