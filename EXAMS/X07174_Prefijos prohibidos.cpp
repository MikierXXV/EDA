#include <iostream>
#include <vector>
using namespace std;

bool ok(int sol, const vector<int>& div) {

	for (int j = 0; j < int(div.size()); ++j)
		if (sol%div[j] == 0) return false;
	return true;
}

void backtrack(int i, const vector<int>& div, int n, int sol) {
	//cout << "i " << i << " sol " << sol << endl;
	if (i == n) cout << sol << endl;
	else {
		for (int j = 0; j < 10; ++j) {
			int sol_i = sol*10 + j;
			if (ok(sol_i, div)) backtrack(i + 1, div, n, sol_i);
		}
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int> v(m);
		for (int i = 0; i < m; ++i) cin >> v[i]; // divisores prohibidos
	
		backtrack(0, v, n, 0);
		cout << "----------" << endl; //string(10, '-');
	}
}
