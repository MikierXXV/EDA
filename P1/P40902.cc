#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){

	map<string,int> m;
	map<string,int>::iterator it;
	string name, op;

	while(cin >> name >> op){
		it = m.find(name);
		int num;
		if (op == "enters"){
			if (it == m.end()) m[name] = 0;
			else cout << name << " is already in the casino" << endl;
		}
		else if (op == "wins"){
			cin >> num;
			if (it != m.end()) it->second += num;
			else cout << name << " is not in the casino" << endl;
		}
		else if (op == "leaves"){
			if (it == m.end())
				cout << name << " is not in the casino" << endl;
			else{
				cout << name << " has won " << it->second << endl;
				m.erase(name);
			} 
		}
	}
	cout << "----------" <<  endl;

	for (it = m.begin(); it != m.end(); ++it){
		cout << it->first << " is winning " << it->second << endl;
	}

}