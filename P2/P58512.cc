#include <iostream>
#include <iomanip>
using namespace std;

double potencia(double x, int n){
	if (n == 0) return 1;
	else {
		double y = potencia(x, n/2);
		if (n%2 == 0) return y*y;
		else return y*y*x;
	}
}

int interest_rate(int min, int max, double b, double q, double f){
	if (min <= max){
		int m = (max+min)/2;
		double ret_bank = potencia(b, m)*q;
		double ret_pav = f*m+q;
		if(ret_pav > ret_bank) return interest_rate(m+1, max, b, q, f);
		else if(ret_pav < ret_bank) return interest_rate(min, m-1, b, q, f);
		else return m;
	}
	else return min;
}


int main() {
	double m, f, r;
	while(cin >> m >> f >> r){
		double bank_rate = (r/100)+1;
		cout << interest_rate(1, 10000000, bank_rate, m, f) << endl;
	}
}