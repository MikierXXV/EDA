#include <iostream>
#include <vector>
using namespace std;

void back_track(int i, vector<int>& longs, int m, int n, int pos){
	if (pos <= m/2 and pos >= -m/2){
		if (i == n){
			cout << pos << endl;
		}
		else{
			back_track(i+1, longs, m, n, pos+longs[i]);
			back_track(i+1, longs, m, n, pos-longs[i]);

		}
	}
}


int main(){
	int m, n;
	cin >> m >> n;
	vector<int> longs(n);
	for (int i = 0; i < n; ++i) cin >> longs[i];

	back_track(0, longs, m, n, 0);
}