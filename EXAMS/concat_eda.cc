#include <iostream>
#include <vector>
using namespace std;


void back_track(const vector<string>& words, vector<bool>& vis, vector<int>& sol, int n){
	if (sol.size() == n) {
		for (int idx : sol) cout << words[idx];
		cout << endl;
	}
	else{
		for (int j = 0; j < n; ++j){
			//words[sol.back()].back() a que accede?
			if(not vis[j] and (sol.size() == 0 or words[sol.back()].back() != words[j][0])){
				vis[j] = true;
				sol.push_back(j);
				back_track(words, vis, sol, n);
				sol.pop_back();;
				vis[j] = false;
			}
		}
	}
}


int main(){

	int n;
	cin >> n;
	vector<string> words(n);
	vector<bool> vis(n, false);
	vector<int> sol;
	for (int i = 0; i < n; ++i) cin >> words[i];
	back_track(words, vis, sol, n);

}