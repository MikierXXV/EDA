#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

struct compare
{
	bool operator()(const pair<string,int>& a, const pair<string, int>& b){
		if(a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	}
};


int main(){

	map<string, pair<bool,int>> m;
	map<string, pair<bool,int>>:: iterator it, it2;

	string op, id;
	while(cin >> op >> id){
		it = m.find(id);
		if(op == "LOGIN"){
			if(it == m.end()) m.insert(make_pair(id,make_pair(true,1200)));
			else it->second.first = true; 
		}
		else if(op == "LOGOUT" and it != m.end()) it->second.first = false;
		else if(op == "PLAY"){
			cin >> id;
			it2 = m.find(id);
			if (it != m.end() and it->second.first and it2 != m.end() and it2->second.first){
				it->second.second += 10;
				it2->second.second -= 10;
				if (it2->second.second < 1200) it2->second.second = 1200;
			}
			else cout << "jugador(s) no conectat(s)" << endl;
		}
		else if(op == "GET_ELO"){
			if(it != m.end()) cout << id << ' ' << it->second.second << endl;
		}
	}
	cout << "RANKING" << endl;
	set<pair<bool,int>,compare> s;
	for(pair<string,pair<bool,int>> p : m) s.insert(make_pair(p.first,p.second.second));
	for (pair<string,int> its : s) cout << its.first << ' ' << its.second << endl;
}