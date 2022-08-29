#include <iostream>
#include <queue>
using namespace std;

int main(){

	char op;
	priority_queue<int> pq;

	while (cin >> op){
		if (op == 'A'){
			if (not pq.empty()){
				cout << pq.top() << endl;
			}
			else cout << "error!" << endl;
		}
		else if (op == 'S'){
			int x;
			cin >> x;
			pq.push(x);
		}
		else if (op == 'R'){
			if (not pq.empty()){
				pq.pop();
			}
			else cout << "error!" << endl;
		}
		else if (op == 'I'){
			int x;
			cin >> x;
			if (not pq.empty()){
				int res = pq.top() + x;
				pq.pop();
				pq.push(res);
			}
			else cout << "error!" << endl;
		}
		else if (op == 'D'){
			int x;
			cin >> x;
			if (not pq.empty()){
				int res = pq.top() - x;
				pq.pop();
				pq.push(res);
			}
			else cout << "error!" << endl;
		}
	}
}