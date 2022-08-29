#include <iostream>
using namespace std;


int expo_modular(int n, int k, int m){
	if (k == 0) return 1;
	else{
		int x = expo_modular(n, k/2, m);
		if(k%2 == 0) return (x*x)%m;
		return ((x*n)%m*x)%m;
	}
}

int main(){
	int n, k, m;
	while (cin >> n >> k >> m){
		cout << expo_modular(n, k, m) << endl;
	}
}