#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef unordered_map<string,pair<bool,int>> map;
typedef unordered_map<string,pair<bool,int>>::iterator it_map;
typedef pair<int,string> Jug;

bool compare(const Jug& j1, const Jug& j2){
	if(j1.first == j2.first) return j1.second < j2.second;
	return j1.first > j2.first;
}

int main(){

	string op;
	map m;
	while (cin >> op){
		if(op == "LOGIN"){
			string j;
			cin >> j;
			it_map it = m.find(j);
			if(it != m.end()){
				if(not (it->second).first) (it->second).first = true;
			} 
			else{
				m[j].first = true;
				m[j].second = 1200;
			}
		}
		else if(op == "LOGOUT"){
			string j;
			cin >> j;
			it_map it = m.find(j);
			if(it != m.end() and (it->second).first)(it->second).first = false;
		}
		else if(op == "PLAY"){
			string j1, j2;
			cin >> j1 >> j2;
			it_map it1 = m.find(j1);
			it_map it2 = m.find(j2);
			if(it1 != m.end() and it2 != m.end() and (it1->second).first and (it2->second).first){
				(it1->second).second += 10;
				(it2->second).second -= 10;
				if((it2->second).second < 1200) (it2->second).second = 1200;
			}
			else cout << "jugador(s) no connectat(s)" << endl;
		}
		else { //GET_ELO
			string j;
			cin >> j;
			cout << j << ' ' << m[j].second << endl;
		}

	}
	vector<Jug> r(m.size());
	int i = 0;
	for(it_map it = m.begin(); it != m.end(); ++it){
		r[i].first = (it->second).second;
		r[i].second = it->first;
		++i;
	}
	cout << endl << "RANKING" << endl;
	sort(r.begin(),r.end(),compare);
	for(int j = 0; j < int(r.size()); ++j){
		cout << r[j].second << ' ' << r[j].first << endl;
	}

}