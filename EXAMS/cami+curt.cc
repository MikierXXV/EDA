#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef vector<set<int>> Graf;

void escriu(const vector<int>& camino, int i){
    int n = camino.size();
    if(i != -1){
        escriu(camino, camino[i]);
        if(i == 0) cout << i;
        else cout << ' ' << i;
    }
}

void bfs(Graf& g, vector<int>& camino){
    int n = g.size();
    vector<int> dist(n, -1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);

    bool fin = false;
    while(not q.empty() and not fin){
        int u = q.front();
        q.pop();
        if(u == n-1) fin = true;
        else{
            int m = g[u].size();
            for(auto it = g[u].begin(); it != g[u].end(); it++){
                int v = *it;
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    camino[v] = u;
                    q.push(v);
                }
            }
        }
    }
}


int main(){
    int n, m;
    while(cin >> n >> m){
        Graf g(n);
        int u, v;
        for (int i = 0; i < m; ++i){
            cin >> u >> v;
            g[u].insert(v);
        }
        vector<int> camino(n, -1);
        bfs(g, camino);
        escriu(camino, n-1);
        cout << endl;
    }
}