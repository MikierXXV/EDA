#include <iostream>
#include <vector>
#include <queue>
#include "Settings.hh"
using namespace std;

typedef pair<int,int> pos;
typedef pair<int, pos> dist_pos;
const int X[4] = {0, 1, 0, -1}
const int Y[4] = {1, 0, -1, 0}
// derecha, abajo, izquierda, arriba

void busca_armas(, int ox, int oy){
    int N = board_rows();
    int M = board_cols();
    pos p = pos_ok(ox,oy);
    dist_pos dp;
    queue<p> q;
    int dist = 0;
    q.push(p)

}
