#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

string ts;
struct compare{
	bool operator()(const string& a, const string& b){
		if (a.length() == b.length()){
			string c = ts.substr(0,a.length());
			if (a == c) return 0;
			if (b == c) return 1;
			if (a < b){
				if (a < c and c < b) return 1;
				return 0;
			}
			else {
				if ( b < c and c < a) return 0;
				return 1;
			}
		}
		else return a.length() > b.length();
	}
};

int main(){

	while (cin >> ts){
		char op;
		string s;
		int cont = 0;
		priority_queue <string,vector<string>,compare> q;
		while (cin >> op and op != 'E'){
			if (op == 'S'){
				cin >> s;
				q.push(s);
			}
			else ++cont;
			while (cont > 0 and not q.empty()){
				cout << q.top() << endl;
				q.pop();
				--cont;
			}
		}
		cout << cont << " ticket(s) left" << endl;
		cout << q.size() << " supporter(s) with no ticket" << endl << endl;

	}
}