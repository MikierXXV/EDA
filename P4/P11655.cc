#include <iostream>
#include <vector>
using namespace std;


void escribe(const vector<int>& sol, const vector<int>& v, int n){
	cout << "{";
	bool primer = true;
	for (int i = 0; i < v.size(); ++i){
		if (v[i] != 0){
			if (not primer) cout << ",";
			else primer = false;
			cout << sol[i];
		}
	}
	cout << "}" << endl;
}

void back_track(int i, int n, int s, vector<int>& v, vector<int>& sol, int s_act, int total){
	if (i == n){
		if (s == s_act) escribe(sol, v, n);
	}
	else if (s_act <= s and s_act+total >= s){
		v[i] = 1;
		back_track(i+1, n, s, v, sol, sol[i]+s_act, total-sol[i]);
		v[i] = 0;
		back_track(i+1, n, s, v, sol, s_act, total-sol[i]);
	}
}

int main(){

	int s, n, total = 0;
	cin >> s >> n;
	vector<int> v(n);
	vector<int> sol(n);
	for (int i = 0; i < n; ++i){
		cin >> v[i];
		total += v[i];
	} 
	if (total >= s) back_track(0, n, s, v, sol, 0, total);
}