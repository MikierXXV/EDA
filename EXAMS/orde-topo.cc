#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef vector<vector<int>> Graf;

void orde_topo(const Graf& g, map<string, int>& pos_tasks, const vector<string>& name_tasks, vector<int>& ge, queue<string>& q){
	int n = g.size();
	priority_queue<string, vector<string>, greater<string>> pq;

	for (int i = 0; i < n; ++i){
		if(ge[i] == 0) pq.push(name_tasks[i]);
	}

	while(not pq.empty()){
		int u  = pos_tasks[pq.top()];
		pq.pop();
		q.push(name_tasks[u]);
		for(int v : g[u]){
			if(--ge[v] == 0) pq.push(name_tasks[v]);
		}
	}
}


int main(){
	int n;
	while (cin >> n){
		map<string, int> pos_tasks;
		vector<string> name_tasks(n);
		for(int i = 0; i < n; ++i){
			string s;
			cin >> s;
		 	name_tasks[i] = s;
		 	pos_tasks[s] = i;
		} 
		int m;
		cin >> m;

		Graf g(n);
		vector<int> ge(n, 0);

		for(int i = 0; i < m; ++i){
			string x, y;
			cin >> x >> y;
			g[pos_tasks[x]].push_back(pos_tasks[y]);
			++ge[pos_tasks[y]];

		}

		queue<string> q;
		orde_topo(g, pos_tasks, name_tasks, ge, q);

		if(q.size() == n){
			while(not q.empty()){
				cout << q.front();
				q.pop();
			}
			cout << endl;
		}
		else cout << "NO VALID ORDERING" << endl;
	}

}