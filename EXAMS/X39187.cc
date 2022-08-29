#include <iostream>
#include <vector>
using namespace std;


void backtracking(string& sol, int i, int monedas, int acciones, int n){
	if(i == n) cout << sol << endl;
	else{
		if(monedas > 0){
			sol[i] = 'b';
			backtracking(sol,i+1,monedas-1,acciones+1,n);
		}	
		if(acciones > 0){
			sol[i] = 's';
			backtracking(sol,i+1,monedas+1,acciones-1,n);
		}
	}
}

int main(){
	int n, c;
	cin >> n >> c;
	string sol(n,' ');
	backtracking(sol, 0, c, 0, n);
}