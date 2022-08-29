#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre){
	if (esq > dre) return -1;
	int m = (esq + dre)/2;
	if (x < v[m]) return posicio(x, v, esq, m-1);
	if (x > v[m]) return posicio(x, v, m+1, dre);
 	return m;
}

int main() {

	double x;
	cin >> x;
	vector<double> v;
	v = {1.0, 4.0, 6.0, 9.0, 10.0, 12.0};
	cout << posicio(x, v, 0, int(v.size())) << endl;
}