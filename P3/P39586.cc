#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <limits>
using namespace std;
            
const int infinit = numeric_limits<double>::infinity();
                       
typedef pair<int, int> arco;
typedef vector<vector<arco> > wgraph;

void dijkstra (wgraph& G, int u, vector<int>& dist, vector<int>& camino, int dest, int& num_caminos) {
    int n = G.size();
    vector<bool> visto(n,false);
    num_caminos = 0;
    dist[u] = 0;
    priority_queue<arco, vector<arco>, greater<arco> > CP;
    CP.push(arco(0, u));
    bool fin = false;
    while (not CP.empty() and not fin) {
         int v = CP.top().second; 
		     CP.pop();
         if (not visto[v]) {
            visto[v] = true;
           	for (int i = 0; i < G[v].size(); ++i) {
               int w = G[v][i].second;
               int d = G[v][i].first;
               if (not visto[w]) {
                  if (dist[w] == infinit or dist[w] > dist[v]+d) {
                      dist[w] = dist[v]+d;
                      CP.push(arco(dist[w], w));
                      camino[w] = v;
                  }
               }
            }
         }
         else if (v == dest) fin = true;
    }
    for (int i = 0; i < dist.size(); ++i){
        if (dist[i] == dist[dest]) ++num_caminos;
    }
}


int main() {
   int n, m;
   while (cin >> n >> m) {
      wgraph G(n);
      for(int i = 0; i < m; ++i) {
         int u, w, p;
         cin >> u >> w >> p;
         G[u].push_back(arco(p,w));
      }
      int ori, dest;
      cin >> ori >> dest;
      vector<int> distancia(n, infinit);
      vector<int> camino(n, -1);
      int num_caminos;
      dijkstra (G, ori, distancia, camino, dest, num_caminos);
      if(distancia[dest] != infinit) {
         cout << "cost " << distancia[dest] << ", " << num_caminos << " way(s)" << endl;
      }
      else cout << "no path from " << ori << " to " << dest << endl;
   }
}