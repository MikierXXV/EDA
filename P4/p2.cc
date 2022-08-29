#include <iostream>
#include <vector>
using namespace std;


void escriu(const vector<string>& v, vector<int>& sol, int n, int p){
	for (int i = 0; i < p; ++i){
		cout << "subconjunt " << i+1 << ": {";
		bool primer = true;
		for (int j = 0; j < n; ++j){
			if (sol[j] == i){
				if (primer){
					primer = false;
				}
				else cout << ",";
				cout << v[j];
			} 
		}
		cout << "}" << endl;
	}
}


void particiones(int i, const vector<string>& v, vector<int>& sol, int n, int p){
	if (i == n){
		escriu(v, sol, p, n);
	}
	else{
		for (int j = 0; j < p; ++j){
			sol[i] = j+1;
			particiones(i+1, v, sol, n, p);
		}
	}
}

int main(){

	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int p; 
	cin >> p;

	vector<int> sol;
	particiones(0, v, sol, n, p);
}