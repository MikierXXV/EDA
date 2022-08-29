#include <iostream>
#include <vector>
using namespace std;


void escriu(const vector<bool>& sol, const vector<int>& numeros){
	cout << "{";
	bool primer = true;
	for (int i = 0; i < sol.size(); ++i){
		if(sol[i]){
			if(primer) primer = true;
			else if(not primer) cout << ",";
			cout << numeros[i];
		}
	}
	cout << "}" << endl;
}


void back(vector<bool>& sol, int i, int n, const vector<int>& numeros, int num, int suma, int total){
	if(i == n){
		if(suma == num) escriu(sol, numeros);
	}
	else if (suma <= num and suma + total >= num){
		sol[i] = false;
		back(sol, i+1, n, numeros, num, suma, total-numeros[i]);
		sol[i] = true;
		back(sol, i+1, n, numeros, num, suma+numeros[i], total-numeros[i]);
	}
}

int main(){
	int num, n;
	cin >> num >> n;
	vector<int> numeros(n);
	vector<bool> sol(n);
	int total = 0; 
	for (int i = 0; i < n; ++i){
		cin >> numeros[i];
		total += numeros[i];
	}
	//si el total es mayor que el numero dado, sino la suma no se puede dar
	if(total >= num) back(sol, 0, n, numeros, num, 0, total);
}