#include <iostream>
#include <vector>
using namespace std;

void back_track(int i, int n, const vector<char>& cons, const vector<char>& voca, vector<bool>& vis_c, vector<bool>& vis_v, string& s){
	if(i == 2*n) cout << s << endl;
	else{
		if(i%2 == 0){
			for (int j = 0; j < n; ++j){
				if(not vis_c[j]){
					s[i] = cons[j];
					vis_c[j] = true;
					back_track(i+1, n, cons, voca, vis_c, vis_v, s);
					vis_c[j] = false;
				}
			}
		}
		else{
			for(int j = 0; j < n; ++j){
				if (not vis_v[j]){
					s[i] = voca[j];
					vis_v[j] = true;
					back_track(i+1, n, cons, voca, vis_c, vis_v, s);
					vis_v[j] = false;
				}
			}
		}
	}
}


int main(){

	int n;
	cin >> n;
	vector<char> c(n);
	for (int i = 0; i < n; ++i) cin >> c[i];
	vector<char> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];	
	vector<bool> vis_c(n, false);
	vector<bool> vis_v(n, false);
	string s(2*n, ' ');
	back_track(0, n, c, v, vis_c, vis_v, s);

}