#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
	return a > b;
}

void escribe(const vector<int>& v, const vector<bool>& sol, int n){
	cout << "{";
	bool primer = true;
	for(int i = 0; i < n; ++i){
		if (sol[i]){
			if (not primer) cout << ",";
			else primer = false;
			cout << v[i];
		}
	}
	cout << "}" << endl;
}

bool back_track(int i, int n, int s, vector<int>& v, vector<bool>& sol, int s_act){
	if (i == n){
		if (s == s_act){
			escribe(v, sol, n);
			return true;
		}
		else return false;
	}
	else{
		sol[i] = true;
		bool b = back_track(i+1, n, s, v, sol, v[i]+s_act);
		if (b) return true;
		else {
			sol[i] = false;
			return back_track(i+1, n, s, v, sol, s_act);
		}
	}
}


int main(){
	int s, n;
	cin >> s >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end(), comp);
	vector<bool> sol(n);
	
	if (not back_track(0, n, s, v, sol, 0)) cout << "no solution" << endl;

}