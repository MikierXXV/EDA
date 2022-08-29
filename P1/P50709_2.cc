#include <iostream>
#include <queue>
using namespace std;

int main(){
	
	char letra;
	priority_queue<int> myCola;

	while(cin >> letra){

		int num;
		if (letra == 'S'){
			cin >> num;
			myCola.push(num);
		}
		else if (letra == 'A' and !myCola.empty()){
			cout << myCola.top() << endl;
		}
		else if (letra == 'R' and !myCola.empty()){
			myCola.pop();
		}
		else if (letra == 'I'){
			cin >> num;
			if (!myCola.empty()){
				num += myCola.top();
				myCola.pop();
				myCola.push(num);
			}
			else cout << "!error" << endl;
		}
		else if (letra == 'D'){
			cin >> num;
			if (!myCola.empty()){
				num -= myCola.top();
				myCola.pop();
				myCola.push(num);
			}
			else cout << "!error" << endl;
		}
		else cout << "!error" << endl;
	}
}