#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef map<string, string> relacions;
typedef map<string, string>::iterator it_map;


int main(){

	string ordre;
	//estructura (map)
	relacions m;
	while (cin >> ordre){
		if (ordre == "info"){
		//Recorrer estructuras imprimir Parelles, 
		//Sols i 10 guiones
		cout << "PARLELLES:" << endl;
		for (it_map it = m.begin(); it != m.end(); ++it){
			if (it->second != "" and it->first < it->second){
				cout << it->first << ' ' << it->second << endl;
			}
		}
		cout << "SOLS:" << endl;
		for (it_map it = m.begin(); it != m.end(); ++it){
			if (it->second == ""){
				cout << it->first << endl;
			}
		}
		cout << "----------" << endl;
		}
		else{
			string x, y;
			cin >> x >> y;
			if(m[x] != ""){
				//x tiene pareja = it_map it = m.find(x)
				//m[m[x]] pareja de z (z,x)
				m[m[x]] = "";
			}
			if(m[y] != ""){
				//x tiene pareja
				//m[m[x]] pareja de z (z,x)
				m[m[y]] = "";
			}
			m[x] = y;
			m[y] = x;
		}
	}

}