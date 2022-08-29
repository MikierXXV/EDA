#include <iostream>
#include <vector>
using namespace std;



int search_pico(const vector<int>& v, int esq, int dre){
	if(esq + 1 >= dre){
		if (v[esq] > v[dre]) return esq;
		else return dre;
	}
	else{
		int m = (esq+dre)/2;
		if (v[m-1] > v[m]) return search_pico(v, esq, m-1);
		else if (v[m+1] > v[m]) return search_pico(v, m+1, dre);
		else return m;
	}
}

//v ordenado crecientemete
bool search_izq(int x, const vector<int>& v, int esq, int dre){
	if (esq > dre) return false;
	else{
		int m = (esq+dre)/2;
		if (x < v[m]) return search_izq(x, v, esq, m-1);
		else if(x > v[m]) return search_izq(x, v, m+1, dre);
		else return true;
	}
}

//v ordenado decrecientemete
bool search_dre(int x, const vector<int>& v, int esq, int dre){
	if (esq > dre) return false;
	else{
		int m = (esq+dre)/2;
		if (x < v[m]) return search_dre(x, v, m+1, dre);
		else if(x > v[m]) return search_dre(x, v, esq, m-1);
		else return true;
	}
}

bool search(int x, const vector<int>& v){
	int n = v.size();
	int pico = search_pico(v, 0, n-1);
	return search_izq(x, v, 0, pico) or search_dre(x, v, pico+1, n-1);

}

int main(){
	int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}