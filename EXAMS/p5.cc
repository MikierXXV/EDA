#include <iostream>
#include <vector>
using namespace std;


void escriu(const vector<string>& par, const vector<int>& sol){
    for (int i = 0; i < sol.size(); ++i){
        cout << par[sol[i]];
    }
   cout << endl;
}

void back_track(int i, int n, vector<string>& par, vector<int>& sol, vector<bool>& vis){
    if(i == n) escriu(par, sol);
    else{
        for (int j = 0; j < n; ++j){
            if(not vis[j] and (i == 0 or par[sol[i-1]].back() != par[j][0])){
                vis[j] = true;
                sol[i] = j;
                back_track(i+1, n, par, sol, vis);
                vis[j] = false;
            }
        }
    }
}


int main(){
    int n;
    cin >> n;

    vector<string> par(n);
    for (int i = 0; i < n; ++i) cin >> par[i];

    vector<int> sol(n);
    vector<bool> vis(n, false);

    back_track(0, n, par, sol, vis);

}