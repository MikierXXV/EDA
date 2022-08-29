#include <iostream>
#include <vector>
using namespace std;


void escriu(const vector<char>& res){
	for (int i = 0; i < int(res.size()); ++i) cout << res[i];
	cout << endl;
}

void paraules(int i, int n, const vector<char>& cons, const vector<char>& voca, 
	vector<bool>& cons_vis, vector<bool>& voca_vis, vector<char>& res){
	if (i == n) escriu(res);
	else{
		for (int j = 0; j < n; ++j){
			/*if (j%2 == 0){
				if (not cons_vis[j]){
					cons_vis[j] = true;
					res[j] = cons[j];
				}

			}
			else{
				if (not voca_vis[j]){
					voca_vis[j] = true;
					res[j] = voca[j];
				}
			}
			paraules(i+1, n, cons, voca, cons_vis, voca_vis, res);
			if (cons_vis[j]){
				cons_vis[j] = false;
			}
			if (voca_vis[j]){
				voca_vis[j] = false;
			}*/
			
		}
	}
}



int main(){
	int n;
	cin >> n;
	vector<char> cons(n);
	vector<char> voca(n);
	vector<char> res(2*n);
	for (int i = 0; i < 2*n; ++i){
		if (i < n/2) cin >> cons[i];
		else cin >> voca[i];
	}
	vector<bool> cons_vis(n, false);
	vector<bool> voca_vis(n, false);
	paraules(0, n, cons, voca, cons_vis, voca_vis, res);
}