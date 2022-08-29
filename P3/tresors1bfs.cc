#include<iostream>
#include<vector>
#include<queue>

using namespace std; //Recorrido en ANCHURA (BFS)
typedef vector<vector<char> > Matriu;
typedef pair<int, int> iipair;

const int X[4] = {0, 1, 0, -1};
const int Y[4] = {1, 0, -1, 0};

bool bfs (Matriu& mapa, int f, int c) {
    bool trobat = false;
    queue<iipair> q;
    q.push(iipair(f,c));
    mapa[f][c] = 'v';
    while (not trobat and not q.empty()) {
        iipair p = q.front();
        q.pop();
        for (int i = 0; i < 4 and not trobat; ++i) {
            int x = p.first + X[i];
            int y = p.second + Y[i];
            if (x>=0 and x<mapa.size() and y>=0 and
            y<mapa[0].size()) {
                if (mapa[x][y] == 't') trobat = true;
                else if (mapa[x][y] == '.'){
                    mapa[p.first][p.second] = 'v';
                    q.push(iipair(x,y));
                }
            }
        }
    }
    return trobat;
}
int main() {
    int n, m;
    cin >> n >> m;
    Matriu mapa(n, vector<char> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> mapa[i][j];
    }
    int f, c;
    cin >> f >> c;
    bool trobat = bfs (mapa, f-1, c-1);
    cout << (trobat? "yes" : "no") << endl;
}
