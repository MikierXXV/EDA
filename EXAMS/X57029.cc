#include <iostream>
#include <vector>
using namespace std;

void backtracking(int i, string& sol, int h, int n){
	if(i == n) cout << sol << endl;
	else{
		if(h > 0){
			sol[i] = 'd';
			backtracking(i+1,sol,h-1,n);
		}
		sol[i] = 'h';
		backtracking(i+1,sol,h,n);
		sol[i] = 'u';
		backtracking(i+1,sol,h+1,n);
	}
}



int main(){

	int n;
	cin >> n;
	string sol(n,' ');
	backtracking(0,sol,0,n);

}