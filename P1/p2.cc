#include <iostream>
#include <set>
#include <vector>
#include <sstream>
using namespace std;


int main(){
	string s;
	while(getline(cin, s)){
		set<int> se;
		int i = 0, cont = 0;
		istringstream iss(s);
		while (iss >> i) se.insert(i);

		set<int>::iterator it = se.begin();
		bool eval;
		while(it != se.end()){
			if (it == se.begin()){
				++cont;
				eval = ((*it)%2 == 0);
			}
			
			else if (eval and (*it)%2 != 0){
				++cont;
				eval = false;
			}
			else if (not eval and (*it)%2 == 0){
				++cont;
				eval = true;
			}
			++it;
		}
		cout << cont << endl;
	}
}