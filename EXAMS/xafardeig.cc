#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main(){

	string s;
	map<string, string> parelles;
	map<string, string>::iterator it;
	while (cin >> s){
		if (s == "liats"){
			string x, y;
			cin >> x >> y;
			if(parelles[x] != "") parelles[parelles[x]] = "";
			if(parelles[y] != "") parelles[parelles[y]] = "";
			parelles[x] = y;
			parelles[y] = x;

		}
		else {
			cout << "PARELLES:" << endl;
			for (it = parelles.begin(); it != parelles.end(); ++it){
				if (it->second != "" and it->first < it->second) cout << it-> first << ' ' << it->second << endl;
			}
			cout << "SOLS:" << endl;

			for (it = parelles.begin(); it != parelles.end(); ++it){
				if (it->second == "") cout << it-> first << endl;
			}
			cout << "----------" << endl;
		}
	}

}