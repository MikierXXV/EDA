#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void escriu(int x, int n, const vector<int>& monedes, const vector<bool>& vis, const vector<bool>& vis1){
	int suma = 0;
	cout << x << " = ";
	for (int i = 0; i < n; ++i){
		if(vis[i]){
			cout << monedes[i];
			suma += monedes[i];
			if(suma != x) cout << " + ";
		}
		if(vis1[i]){
			cout << monedes[i] << "p";
			suma += monedes[i];
			if(suma != x) cout << " + ";
		}
	}
	cout << endl;
}

void back_track(int i, int x, int n, const vector<int>& monedes, vector<bool>& vis, vector<bool>& vis1, int suma){
	if (suma == x) escriu(x, n, monedes, vis, vis1);
	else if (x > suma and i < n){
		if(monedes[i]+suma <= x){
			if(not vis[i]){
				vis[i] = true;
				back_track(i, x, n, monedes, vis, vis1, suma+monedes[i]);
				vis[i] = false;
			}
			if(not vis1[i]){
				vis1[i] = true;
				back_track(i+1, x, n, monedes, vis, vis1, suma+monedes[i]);
				vis1[i] = false;
			}
			back_track(i+1, x, n, monedes, vis, vis1, suma);
		}
	}
}

int main(){
	int x, n;
	while(cin >> x >> n ){
		vector<int> monedes(n);
		for (int i = 0; i < n; ++i) cin >> monedes[i];
		sort(monedes.begin(), monedes.end());
		vector<bool> vis(n, false);
		vector<bool> vis1(n, false);
		back_track(0, x, n, monedes, vis, vis1, 0);
		cout << string(10, '-') << endl;
	}
}