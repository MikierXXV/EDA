#include <iostream>
#include <vector>
using namespace std;


void back_track(int i, string& s, int n, int mone, int accio){
	if(i == n) cout << s << endl;
	else{
		if(mone > 0){
			s[i] = 'b';
			back_track(i+1, s, n, mone-1, accio+1);	
		}
		if(accio > 0){
			s[i] = 's';
			back_track(i+1, s, n, mone+1, accio-1);
		}
	}
}


int main(){

	int n, c;
	cin >> n >> c;
	string s(n, ' ');
	back_track(0, s, n, c, 0);

}