#include <iostream>
#include <vector>
using namespace std;


void escribir(const vector<string>& v, const vector<int>& sol, int n, int p){
	for(int i = 0; i < p; ++i){
		cout << "subconjunt " << i+1 << ": {";
		bool primer = true;
		for (int j = 0; j < n; ++j){
			if (sol[j] == i){
				if (not primer) cout << ",";
				else primer = false;
				cout << v[j];
			}
		}
		cout << "}" << endl;
	} 
	cout << endl;
}

void particiones(vector<string>& vs, int n, int i, vector<int>& sol, int p){
	if (i == n) escribir(vs, sol, n, p);
	else{
		for (int j = 0; j < p; ++j){
			sol[i] = j;
			particiones(vs, n, i+1, sol, p);
		}
	}
}

int main(){

	int n_words, n_subconj;
	cin >> n_words;

	vector<string> words(n_words);
	for (int i = 0; i < n_words; ++i) cin >> words[i];
	cin >> n_subconj;
	
	vector<int> sol(n_words);

	particiones(words, n_words, 0, sol, n_subconj);


}