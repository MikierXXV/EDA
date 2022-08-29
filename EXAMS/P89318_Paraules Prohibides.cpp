#include <iostream>
#include <vector>
using namespace std;

void backtrack(string& sol, vector<bool>& usat, int i, int n) {
	if (i == n) cout << sol << endl;
	else {
		for (int j = 0; j < n; ++j) {
			if (not usat[j] and (i == 0 or (sol[i - 1] + 1 != 'a' + j))) {
				sol[i] = 'a' + j;
				usat[j] = true;
				backtrack(sol, usat, i + 1, n);
				usat[j] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	string sol(n, 'a');
	vector<bool> usat(n, false);
	backtrack(sol, usat, 0, n);
}
