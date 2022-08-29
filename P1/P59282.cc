#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {

	cout.setf(ios::fixed);
	cout.precision(4);

	string s;
	map<int, int> m;
	map<int, int>::iterator it;
	int cont = 0, avg = 0;

	while (cin >> s){
		if (s == "number"){
			int num;
			cin >> num;
			it = m.find(num);
			if (it != m.end()) ++it->second;
			else m[num] = 1;
			++cont;
			avg += num;
			
			
		}
		else if (s == "delete"){
			if (m.begin() != m.end()){
				--cont;
				avg -= m.begin()->first;
				--m.begin()->second;
				if (m.begin()->second == 0) m.erase(m.begin());
			}
		}
		if (m.begin() == m.end()) cout << "no elements" << endl;
		else cout << "minimum: " << m.begin()->first << ", " << "maximum: " 
			<< (--m.end())->first << ", " << "average: " << avg/double(cont) << endl;
	}
}