#include <iostream>
#include <vector>
using namespace std;


void escribe(const vector<string>& s, const vector<int>& sol, int n, int p){
	for (int i = 0; i < p; ++i){
		cout << "subconjunt " << i+1 << ": {";
		bool primer = true;
		for (int j = 0; j < n; ++j){
			if (sol[j] == i){ 
				if (not primer) cout << ",";
				else primer = false;
				cout << s[j]; 
			}
		}
		cout << "}" << endl;
	}
	cout << endl;
}

void back_track(int i, int n, vector<string>& s, vector<int>& sol, int p){
	if (i == n) escribe(s, sol, n, p);
	else{
		for (int j = 0; j < p; ++j){
			sol[i] = j;
			back_track(i+1, n, s, sol, p);
		}
	}
}


int main(){

	int n, p;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) cin >> s[i];
	cin >> p;
	vector<int> sol(n);

	back_track(0, n, s, sol, p);

}