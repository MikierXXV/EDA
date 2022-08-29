#include <iostream>
#include <vector>
using namespace std;


int num_inversion(vector<int>& v, int esq, int m, int dre){
	vector<int> b(dre-esq+1);
	int i = esq, j = m+1, k = 0, num = 0;
	while(i <= m and j <= dre){
		if (v[i] <= v[j]) b[k++] = v[i++];
		else{
			b[k++] = v[j++];
			num += m+1-i;
		}
	}
	while(i <= m) b[k++] = v[i++];
	while(j <= dre) b[k++] = v[j++];
	for(k = 0; k < b.size(); ++k) v[esq+k] = b[k];
	return num;
}


int inversion (vector<int>& v, int esq, int dre){
	int num = 0;
	if (esq < dre){
		int m = (esq+dre)/2;
		num = inversion(v, esq, m);
		num += inversion(v, m+1, dre);
		num += num_inversion(v, esq, m, dre);
	}
	return num;
}


void read_vector(vector<int>& v){
	for (int i = 0; i < v.size(); ++i){
		cin >> v[i];
	}
}


int main() {
	int n;
	while (cin >> n){
		vector<int> v(n);
		read_vector(v);
		cout << inversion(v, 0, v.size()-1) << endl;
	}
}