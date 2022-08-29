#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

typedef vector<queue<string>> colas;

void leer_colas(colas& cj){
	int n = cj.size();
	for (int i = 0; i < n; ++i){
		string s;
		getline(cin,s);
		istringstream ss(s);
		string nom;
		while (ss >> nom){
			cj[i].push(nom);
		}
	}
}

void escribir_colas(colas& cj){
	int n = cj.size();
	for (int i = 0; i < n; ++i){
		cout << "cua " << i+1 << ":";
		while (not cj[i].empty()){
			cout << " " << cj[i].front();
			cj[i].pop();
		}
		cout << endl;
	}
}

int main(){

	int n;
	cin >> n;
	string s;
	getline(cin,s);
	colas cj(n);
	leer_colas(cj);
	cout << "SORTIDES" << endl;
	cout << string(8,'-') << endl;
	string ordre;
	while (cin >> ordre){
		if (ordre == "SURT"){
			int n_cua;
			cin >> n_cua;
			if (1 <= n_cua and n_cua <= n and not cj[n_cua-1].empty()){
				cout << cj[n_cua-1].front() << endl;
				cj[n_cua-1].pop();
			}
		}
		else{ //ENTRA
			string client;
			int n_cua;
			cin >> client >> n_cua;
			if (1 <= n_cua and n_cua <= n){
				cj[n_cua-1].push(client);
			}
		}
	}
	cout << endl;
	cout << "CONTINGUTS FINALS" << endl << string(17,'-') << endl;
	escribir_colas(cj);
}