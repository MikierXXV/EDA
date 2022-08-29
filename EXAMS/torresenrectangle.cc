#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tablero;

void escriu(const Tablero& t, int f, int c){
	for (int i = 0; i < f; ++i){
		for (int j = 0; j < c; ++j) cout << t[i][j];
		cout << endl;
	}
	cout << endl;
}

bool pos_ok(const Tablero& t, int f, int j){
	for(int i = 0; i < f; ++i){
		if(t[i][j] == 'R') return false;
	}
	return true;
}


void back_track(int i, Tablero& t, int f, int c){
	if(i == f) escriu(t, f, c);
	else{
		for (int j = 0; j < c; ++j){
			if(pos_ok(t, i, j)){
				t[i][j] = 'R';
				back_track(i+1, t, f, c);
				t[i][j] = '.';
			}
		}
	}
}


int main(){
	int f, c;
	cin >> f >> c;
	Tablero t(f, vector<char>(c, '.'));
	back_track(0, t, f, c);
}