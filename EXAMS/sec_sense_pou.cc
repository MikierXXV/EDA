#include <iostream>
#include <vector>
using namespace std;


void escriu(const vector<int>& sol, int n){
	cout << '(';
	for (int i = 0; i < n; ++i){
		if (i != 0) cout << ',';
		cout << sol[i];
	}
	cout << ')' << endl;
}


bool pou(int esq, int mig, int dre){
	return esq+dre > 2*mig;
}

void back_track(int i, vector<int>& sol, vector<bool>& vis, int n){
	if (i == n) escriu(sol, n);
	else{
		for (int j = 0; j < n; ++j){
			if (not vis[j]){
				//i <= 1 and (!!!i > 1 este es el negado no hace falta!!! and not pou)
				if(i <= 1 or not pou(sol[i-2], sol[i-1], j+1)){
					vis[j] = true;
					sol[i] = j+1;
					back_track(i+1, sol, vis, n);
					vis[j] = false;
				}
			}
		}
	}
}


int main(){
	int n;
	cin >> n;
	vector<int> sol(n);
	vector<bool> vis(n, false);
	back_track(0, sol, vis, n);
}