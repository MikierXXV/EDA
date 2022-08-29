#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tablero;

const int X[8] = {-1, -1, 0, 1, 1, 1, 0,-1};
const int Y[8] = {0, 1, 1, 1, 0, -1, -1,-1};


bool pos_ok(int x, int y, int n){
	return x >= 0 and y >= 0 and x < n and y < n;
}

bool amenaza(int x, int y, const Tablero& t, int n){
	for (int i = 0; i < 8; ++i){
		int next_x = x + X[i];
		int next_y = y + Y[i];
		if (pos_ok(next_x, next_y, n) and t[next_x][next_y] == 'K') return true;
	}
	return false;
}

void escriu(const Tablero& t, int n){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << t[i][j];
		}
		cout << endl;
	}
	cout << string(10, '-') << endl;
}

void back_track(int i, int n, int reis, Tablero& t, int nreis){
	if(reis == nreis) escriu(t, n);
	else if (i < n*n){
		int x = i/n;
		int y = i%n;
		if(t[x][y] == '.' and not amenaza(x, y, t, n)){
			t[x][y] = 'K';
			back_track(i+1, n, reis, t, nreis+1);
		}
		t[x][y] = '.';
		back_track(i+1, n, reis, t, nreis);
	}
}


int main(){
	int n, reis;
	cin >> n >> reis;
	Tablero t(n, vector<char>(n, '.'));
	back_track(0, n, reis, t, 0);
}