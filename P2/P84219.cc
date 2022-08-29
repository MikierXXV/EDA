#include <iostream>
#include <vector>
using namespace std;


int cerca_first_occur(double x, const vector<double>& v, int esq, int dre){
	if(esq > dre) return -1;
	int m = (esq + dre)/2 ;
	if (esq == dre){
		if(x == v[esq]) return esq;
		else return -1;
	}
	if (x <= v[m]) return cerca_first_occur(x, v, esq, m);
	else return cerca_first_occur(x, v, m+1, dre);
	
}


int first_occurrence(double x, const vector<double>& v){
	return cerca_first_occur(x, v, 0, int(v.size()-1));
}



int main() {

	double x;
	cin >> x;
	vector<double> v;
	v = {1.0, 4.0, 6.0, 9.0, 10.0, 12.0};
	cout << first_occurrence(x, v) << endl;
}