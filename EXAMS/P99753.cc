#include <iostream>
#include <vector>
using namespace std;



bool cerca_dicot(int x, const vector<double>& v, int esq, int dre){
	if(esq > dre) return esq;
	int m = (esq+dre)/2;
	if(x < v[m]) return cerca_dicot(x,v,esq,m-1);
	else if (x > v[m]) return cerca_dicot(x,v,m+1,dre);
	return true;

}

bool search_rec(int x, const vector<int>& v, int esq, int dre){
	if(esq+1 == dre) return v[esq] == x or v[dre] == x;
	else{
		int m = (esq+dre)/2;
		if(v[esq] <= x){
			if(x <= v[m]) return cerca_dicot(x,v,esq,m);
			else{
				return search_rec(x, v, m, dre)
			}
		}
		else{
			if(v[m] <= x and x <= v[dre]) return cerca_dicot(x, v, m, dre);
			return search_rec(x, v, esq, m);
		}
	}
}


bool search(int x, const vector<int>& v){
	return search(x, v, 0, v.size());
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	
	int x;
	cin >> x;
	cout << search(x,v) << endl;
	
}