#include <iostream>
#include <vector>
using namespace std;

void back_track(int i, string& s, int n, int na, int nb){
	if (i == n) cout << s << endl;
	else{

		if (abs((na+1) - nb) <= 2){
			s[i] = 'a';
			back_track(i+1, s, n, na+1, nb);
		}
		if (abs(na - (nb+1)) <= 2){
			s[i] = 'b';
			back_track(i+1, s, n, na, nb+1);
		}

	}

}

int main(){

	int n;
	cin >> n;
	string s(n, ' ');
	int na = 0, nb = 0;
	back_track(0, s, n, na, nb);

}