#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& res, int n){
	cout << "(";
	for (int i = 0; i < n; ++i){
		if (i == 0) cout << res[i];
		else cout << "," << res[i];
	}
	cout << ")" << endl;
}

void back_track(int i, vector<int>& res, vector<bool>& vis, int n, int d){
	if (i == n) escriu(res, n);
	else{
		for (int j = 0; j < n; ++j){
			if(not vis[j] and (i == 0 or abs(res[i-1]-(j+1)) <= d)){
				res[i] = j+1;
				vis[j] = true;
				back_track(i+1, res, vis, n, d);
				vis[j] = false;
			}
		}
	}
}

int main(){
	int n, d;
	cin >> n >> d;
	vector<int> res(n);
	vector<bool> vis(n, false);
	back_track(0, res, vis, n, d);
}