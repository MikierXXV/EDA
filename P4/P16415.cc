#include <iostream>
#include <vector>
using namespace std;





bool legal(int i, vector<int>& t, int n){
	for (int k = 0; k < i; ++k){
		if (t[k] == t[i] or t[k]-k == t[i]-i or t[k]+k == t[i]+i){
			return false;
		}
	}
	return true;
}

void n_reinas(int i, vector<int>& t, int n, int cont){
	if (i == n) return;
	else{
		for (int j = 0; j < n; ++j){
			t[i] = j;
			if (legal(i, t, n)) n_reinas(i+1, t, n, cont+1);
		}
	}
}

int main(){
	int n, cont = 0;
	cin >> n;
	vector<int> t(n);
	n_reinas(0, t, n, cont);
	cout << cont << endl;
}