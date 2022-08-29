#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int back_track(int i, int x, int n, const vector<int>& monedes, int suma, int max){
	if(suma > x or suma + max < x) return 0;
	if (i == n) return 1;
	int cont = 0;
	for (int k = 0; k <= 2; ++k){
		cont += back_track(i+1, x, n, monedes, suma+k*monedes[i], max-2*monedes[i]);
	}
	return cont;
}

int main(){
	int x, n;
	while(cin >> x >> n){
		vector<int> monedes(n);
		int suma = 0;
		for (int i = 0; i < n; ++i){
			cin >> monedes[i];
			suma += monedes[i];
		} 
		cout << back_track(0, x, n, monedes, 0, 2*suma) << endl;
	}
}