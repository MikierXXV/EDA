#include <iostream>
#include <vector>
using namespace std;

void escr_string(const string& s){
	for (int i = 0; i < s.size(); ++i){
		cout << s[i];
	}
}
void escribe(const vector<string>& sol, int n){
	cout << '(';
	bool primer = true;
	for (int i = 0; i < n; ++i){
		if(primer) primer = false;
		else cout << ",";
		escr_string(sol[i].second);
	}
	cout << ')' << endl;
}



void back_track(vector<pair<int,string>>& sol, vector<bool>& usar, int n, int i){
	if (i == n){
		escribe(sol, n);
	}
	else {
		for (int j = 0; j < n; ++j){
			if (not usar[j]){
				sol[i].first = j+1;
				//marcar
				usar[j] = true;
				//llamada 
				back_track(sol, usar, n, i+1);
				//desmarcar
				usar[j] = false;
			}
		}
	}
}

int main(){

	int n;
	cin >> n;
	string s;
	for(int i = 0; i < n; ++i){
		cin >> s;
	}
	vector<pair<int,string>> sol(n);
	vector<bool> usar(n, false);

	back_track(sol, usar, n, 0);
}