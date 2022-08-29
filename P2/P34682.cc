#include <iostream>
#include <vector>
using namespace std;


int fix_point(const vector<int>& v, int& a, int esq, int dre){
	if (esq <= dre){
		int m = (esq+dre)/2;
		if(v[m]+a < m+1) return fix_point(v, a, m+1, dre);
		else if (v[m]+a > m+1) return fix_point(v, a, esq, m-1);
		else {
			int point = fix_point(v, a, esq, m-1);
			if(point == -1) return m+1;
			return point;
		}
	}
	return -1;
}

int main(){
	int n, s = 1, m, x;
	while (cin >> n){
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		cin >> m;
		cout << "Sequence #" << s << endl;
		for (int i = 0; i < m; ++i){
			cin >> x;
			int res = fix_point(v, x, 0, n-1);
			if (res != -1) cout << "fixed point for " << x << ": " << res << endl;
			else cout << "no fixed point for " << x << endl;
		}
		cout << endl;
		++s;
	}
}