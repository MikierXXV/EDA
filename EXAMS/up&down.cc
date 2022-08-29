#include <iostream>
#include <vector>
using namespace std;

void backtrack(int i, string& s, int n, int mov){
	if (i == n) cout << s << endl;
	else{
		
		if (mov > 0){
			s[i] = 'd';
			backtrack(i+1, s, n, mov-1);
		}
		s[i] = 'h';
		backtrack(i+1, s, n, mov);

		s[i] = 'u';
		backtrack(i+1, s, n, mov+1);

	}
}

int main(){
	int n;
	cin >> n;
	string s(n, ' ');
	int mov = 0;
	backtrack(0, s, n, mov);
}