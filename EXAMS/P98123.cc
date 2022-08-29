#include <iostream>
#include <string>
#include <set>
using namespace std;

typedef set<int> Set;
typedef set<int>::iterator it_set;

int main(){

	int n;
	cin >> n;
	string op;
	Set s;
	while (cin >> op){
		if (op == "deixar"){
			int val;
			cin >> val;
			s.insert(val);
		}
		else if(op == "endur"){
			int val;
			cin >> val;
			it_set it = s.find(val);
			if(it != m.end()){
				s.pop();
			}
		}
		int suma;
		int i = 0;
		for (it_set it = s.begin(); it < n; ++it){
			suma += s[i];
			++i;
		}
		cout << suma << endl;
	}
}