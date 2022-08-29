#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, string> Jug;

bool compare(const Jug& j1, const Jug& j2){
	if (j1.first == j2.first){
		return j1.second < j2.second;
	}
	return j1.first > j2.first;
}


int main() {

	string op;
	unordered_map<string, pair<bool, int>> m;
	unordered_map<string, pair<bool, int>>:: iterator it, it2;

	while(cin >> op){
		if (op == "LOGIN"){
			string name;
			cin >> name;
			it = m.find(name);
			if (it != m.end()){
				if (not it->second.first) it->second.first = true;
			}
			else{
				m[name].first = true;
				m[name].second = 1200;
			}
		}
		else if (op == "LOGOUT"){
			string name;
			cin >> name;
			it = m.find(name);
			if (it != m.end() and it->second.first)
				it->second.first = false;
		}
		else if (op == "PLAY"){
			string n1, n2;
			cin >> n1 >> n2;
			it = m.find(n1);
			it2 = m.find(n2);
			if (it->second.first and it2->second.first and 
				it != m.end() and it2 != m.end()){
				it->second.second += 10;
				it2->second.second -= 10;
				if (it2->second.second < 1200)
					it2->second.second = 1200;
			}
			else cout << "jugador(s) no connectat(s)" << endl;
		}
		else if (op == "GET_ELO"){
			string name;
			cin >> name;
			it = m.find(name);
			if (it != m.end()) cout << name << ' ' << it->second.second << endl;
		}
	}

	vector<Jug> r(m.size());
	int i = 0;
	for (it = m.begin(); it != m.end(); ++it){
		r[i].first = it->second.second;
		r[i].second = it->first;
		++i;
	}	
	cout << endl << "RANKING" << endl;
	sort(r.begin(), r.end(), compare);
	for (int j = 0; j < int(r.size()); ++j){
		cout << r[j].second << ' ' << r[j].first << endl;
	}

}