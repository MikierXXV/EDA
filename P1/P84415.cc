#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){

	string op;
	map<string, int> m;
	map<string, int>::iterator it, it2;

	while (cin >> op){
		if (op == "minimum?"){
			if (m.empty()) cout << "infinite minimum" << endl;
			else {
				it = m.begin();
				cout << "minimum: " << it->first << ", " 
				<< it->second << " time(s)" << endl;
			}
		}
		else if (op == "maximum?"){
			if (m.empty()) cout << "infinite maximum" << endl;
			else {
				it2 = --(m.end());
				cout << "maximum: " << it2->first << ", " 
				<< it2->second << " time(s)" << endl;
			}
		}
		else if (op == "store"){
			string w;
			cin >> w;
			it = m.find(w);
			if (it == m.end()) m[w] = 1;
			else it->second += 1;
		}
		else if (op == "delete"){
			string w;
			cin >> w;
			it = m.find(w);
			if (it != m.end()) {
				it->second -= 1;
				if (it->second < 1) m.erase(w);
			}
		}
	}

}