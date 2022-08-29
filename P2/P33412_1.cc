#include <iostream>
#include <vector>
using namespace std;


bool resistant_search_rec(double x, const vector<double>& v, int esq, int dre){
    if (dre < esq) return false;
    int m = (esq+dre)/2;
    if (x == v[m]) return true;
    else if (x < v[m]){
        if (m+1 < dre and v[m+1] == x) return true;
        else resistant_search_rec(x,v,esq,m-1);
    }
    else{
        if (m-1 >= esq and v[m-1] == x) return true;
        else resistant_search_rec(x,v,m+1,dre);
    }
}

bool resistant_search(double x, const vector<double>& v){
    return resistant_search_rec(x,v,0,v.size()-1);
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}
