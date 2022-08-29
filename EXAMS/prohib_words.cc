#include <iostream>
#include <vector>
using namespace std;


void back_track(int i, vector<bool>& vis, string& s, int n){
	if (i == n) cout << s << endl;
	else{
		for (int j = 0; j < n; ++j){
			if (not vis[j] and (i == 0 or (s[i-1] + 1 != 'a'+j))){
				s[i] = 'a' + j;
				vis[j] = true;
				back_track(i+1, vis, s, n);
				vis[j] = false;
			}
		}
	}
}


int main(){
	int n;
	cin >> n;
	string s(n, 'a');
	vector<bool> usat(n, false);
	back_track(0, usat, s, n);
}