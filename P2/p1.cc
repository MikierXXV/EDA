#include <iostream>
#include <vector>
using namespace std;

/*
bool resistant_search(double x, const vector<double>& v){
	if (v.size() == 0) return false;
	int esq = 0, dre = v.size()-1, m;
	else{
		int m = (esq+dre)/2;
		bool rest = v[m] > v[m+1];
		if(x < v[m] and not rest) return resistant_search_rec(x, v, esq, m-1);
		else if ( x > v[m] and not rest) return resistant_search_rec(x, v, m+1, dre);
		else if ( x < v[m] and rest) return resistant_search_rec(x, v, l, m-1);
		else if ( x > v[m] and rest) return resistant_search_rec(x, v, m+1, dre);
		
	}
}*/

bool resistant_search(double x, const vector<double>& v){
	if (v.size() == 0) return false;
	int esq = 0, dre = v.size()-1, m;
	while (esq + 1 < dre){
		m = (esq + dre)/2;
		if (v[m] == x or v[m-1] == x or v[m+1] == x) return  true;
		else if (v[m] > x) dre = m;
		else esq = m;
	}
	return (x == v[esq] or x == v[dre]);
}
