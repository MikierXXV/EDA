#include <iostream>
#include <set>
#include <sstream>
using namespace std;


int main() {
	string s;
	while (getline(cin, s)){
		set<int> se;
		istringstream iss(s);
		int num, cont = 0;
		while(iss >> num) se.insert(num);

		bool evalua;
		set<int>::iterator it = se.begin();
		while (it != se.end()){
			if (it == se.begin()){
				++cont;
				evalua = (*it%2 == 0);
			}
			else if (evalua and (*it%2 != 0)){
				++cont;
				evalua = false;
			}
			else if (not evalua and (*it%2 == 0)){
				++cont;
				evalua = true;
			}
			++it;
		}
		cout << cont << endl;
	}
}