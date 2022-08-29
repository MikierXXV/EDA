#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef map<string,int> mapa;
typedef map<string,int>::iterator it_map;



int main(){

	int n;
	while (cin >> n){
		mapa m;
		int max = 0;
		//lectura juego inicial cumpliendo la resticcion
		for(int i = 0; i < n; ++i){
			string s;
			cin >> s;
			++m[s];
			++max;
		}
		int j; 
		cin >> j;
		for(int i = 0; i < j; ++i){
			string s;
			cin >> s;
			int num_s = m[s];
			if(num_s +1 <= max-num_s){
				++m[s];
				++max;
			}
		}
		for(it_map it = m.begin(); it != m.end(); ++it){
			cout << it->first << ' ' << it->second << endl;
		}
		cout << string(20,'-') << endl;
	}
}