#include <iostream>
#include <vector>
using namespace std;


bool search_decreciente(int x, const vector<int>& v, int esq, int dre){
	if(esq > dre) return esq;
	int m = (esq+dre)/2;
	if(x > v[m]) return search_decreciente(x,v,esq,m-1);
	else if (x < v[m]) return search_decreciente(x,v,m+1,dre);
	return true;
}

bool search_creciente(int x, const vector<int>& v, int esq, int dre){
	if(esq > dre) return esq;
	int m = (esq+dre)/2;
	if(x < v[m]) return search_creciente(x,v,esq,m-1);
	else if (x > v[m]) return search_creciente(x,v,m+1,dre);
	return true;
}

int search_pico(int x, const vector<int>& v, int esq, int dre){
	if(esq+1 >= dre){
		if(v[esq] < v[dre]) return dre;
		return esq;
	} 
	int m = (esq+dre)/2;
	if(v[m] < v[m-1]) return search_pico(v, esq, m-1);
	else if(v[m] < v[m+1]) return search_pico(v,m+1,dre);
	else return m;
}


bool search(int x, const vector<int>& v){
	int n = v.size();
	int j = search_pico(v, 0, n-1);
	return search_creciente(x, v, 0, j) or search_decreciente(x, v, j, n-1);
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