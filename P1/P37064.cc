#include <iostream>
#include <set>
#include <vector>
using namespace std;


int main() {

	string s;
	set<string> se;
	set<string>::iterator it = se.begin(), m;
	cin >> s;
	while(s != "END"){
		it = se.insert(it, s);
		cout << s << endl;
		m = se.begin();
		while (cin >> s and s != "END"){
			se.insert(it, s);
			if (s < *m and se.size() % 2 == 0) --m;
			else if (s > *m and se.size() % 2 != 0) ++m;
			cout << *m << endl;
		}
	}
}