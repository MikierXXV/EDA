#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Matriu;
typedef pair<int,int> iipair;

const int x[4]={0,1,0,-1};
const int y[4]={1,0,-1,0};

bool pos_valida(int r, int c, Matriu& M){
	if(r<0 or c<0 or r>=M.size() or c>=M[0].size()) return false;
	else if(M[r][c]=='X') return false;
	else return true;
}

void dfs_rec(Matriu &M, int r, int c, int& suma){
    if(pos_valida(r,c,M)){
        if(M[r][c] == 't'){
            ++suma;
            M[r][c] = 'X';
        } 
        for(int i = 0; i < 4; i++){
            M[r][c]='X';
            dfs_rec(M,r+x[i],c+y[i],suma);
        }
    }
}

int main(){
	int n,m,r,c;
	cin>>n>>m;
	Matriu M(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>M[i][j];
		}
	}
	cin>>r>>c;
    int suma = 0;
	dfs_rec(M, r-1, c-1, suma);
    cout << suma << endl;
}