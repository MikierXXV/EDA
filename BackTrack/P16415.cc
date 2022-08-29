#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> MatrixB;


void backtrack(int i, MatrixB& vis, int suma, int n){
	if (i == n) return;
	else {
		for (int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){ 
				if (not vis[j][k]){
					vis[j][k] = true;
					backtrack(i+1, vis, suma+1, n);
					vis[j][k] = false;
				}
			}
		}
	}
}

int main(){

	int n;
	int suma = 0;
	cin >> n;
	MatrixB vis(n, vis[0].size());
	backtrack(0, vis, suma, n);
	cout << suma << endl;

}