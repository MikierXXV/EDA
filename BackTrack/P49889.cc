#include <iostream>
#include <vector>
using namespace std;



int main(){

	int n;
	cin >> n;

	vector<char> cons(n);
	vector<char> voc(n);
	for (int i = 0; i < n; ++i) cin >> cons[i];
	for (int i = 0; i < n; ++i) cin >> voc[i];
	/*
	for (int i = 0; i < 2*n; ++i){
		if (i < n) cin >> cons[i];
		else cin >> voc[i];
	}
	*/
	


}