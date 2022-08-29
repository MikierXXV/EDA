#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


typedef pair<int, int> ArcP;
typedef vector<vector<ArcP>> Graf;

const int infinite = INT_MAX;


int dijsktra(const Graf& g, const vector<int>& w, int n, int ini, int fin){
    vector<int> dist(n, infinite);
    vector<bool> vis(n, false);

    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> pq;

    dist[ini] = 0;
    pq.push({0, ini});

    while(not pq.empty()){
        int u = pq.top().second;
        int c = pq.top().first;
        pq.pop();
        if (not vis[u]){
            vis[u] = true;
            if(u == fin) return dist[u];
            for (ArcP p : g[u]){
                int v = p.second;
                int cost = p.first;
                if(v != fin) cost += w[v];
                if (dist[v] > dist[u] + cost){
                    dist[v] = dist[u] + cost;
                    pq.push({dist[v],v});
                }
            }   
        }
    }
    return infinite;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];

    Graf g(n);

    for (int i = 0; i < m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
    }

    int x, y;
    while(cin >> x >> y){
        int res = dijsktra(g, w, n, x, y);
        cout << "c(" << x << "," << y << ") = ";
        if (res == infinite) cout << "+oo" << endl;
        else cout << res << endl;
    }
}