#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> ArcP; //dist y adyecente
typedef vector<vector<ArcP>> Graf;

const int infinit = INT_MAX;

int dijk(conts Graf& g, int ini, int fin){
	int n = g.size();
	vector<bool> vis(n, false);
	vector<int> dist(n, infinit);
	priority_queue<ArcP, vector<ArcP>, greater<ArcP>> pq;

	dist[ini] = 0;
	pq.push({0,ini});

	while(not pq.empty()){
		ArcP act = pq.top();
		pq.pop();
		if(act.second == fin) return dist[act.second];
		else if (not vis[act.second]){
			vis[act.second] = true;
			for (ArcP seg : g[act.second]){
				int v = seg.second;
				int d = seg.first;
				int d_max = max(d, dist[u]);
				if (d_max < dist[v]){
					d_max = dist[v];
					pq.push({d_max, v});
				}
			}
		}
	}
	return infinit;
}


int main(){
	int n, m;
	while(cin >> n >> m){
		Graf g(n);
		for (int j = 0; j < m; ++j){
			int u, v, d;
			cin >> u >> v >> d;
			g[u].push_back({d, v});
		}

		cout << dijk(g, 0, m) << endl;
	}

}