#include <iostream>
#include <vector>
using namespace std;


void back_track(int i, const vector<string>& words, vector<bool>& vis, string& s, int n){
	if (i == n) cout << s << endl;
	else{
		for (int j = 0; j < n; ++j){
			if(not vis[j] and (s.size() == 0)){
				s = words[j];
				vis[j] = true;
				s += words[j+1];
				back_track(i+1, words, vis, s, n);
				s.pop_back();;
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
	for (int i = 0; i < n; ++i) cin >> words[i];
	string s(" ");
	back_track(0, words, vis, s, n);

}