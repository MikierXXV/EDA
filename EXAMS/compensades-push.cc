#include <iostream>
#include <vector>
using namespace std;

void back_track(int i, string& s, int n, int na, int nb){
	//consulto siempre poda y si es el caso break
	if (abs(na-nb) > 2) return;
	if (i == n) cout << s << endl;
	else{
		
		s.push_back('a');
		back_track(i+1, s, n, na+1, nb);
		s.pop_back();


		s.push_back('b');
		back_track(i+1, s, n, na, nb+1);
		s.pop_back();
	
	}
}

int main(){

	int n;
	cin >> n;
	string s;
	int na = 0, nb = 0;
	back_track(0, s, n, na, nb);

}