#include <iostream>
#include <set>
#include <string>
using namespace std;

struct comp{
	bool operator()(const string& a, const string& b){
		if (a.length() == b.length()) return a < b;
		return a.length() < b.length();
	}
};

int main(){
	string word;
	int game = 1;
	set<string>::iterator its;
	set<string,comp>::iterator itd;

	while ( word != "QUIT"){
		set<string> has;
		set<string,comp> had;
		while (cin >> word and word != "END" and word != "QUIT"){
			its = has.find(word);
			if (its == has.end()){
				has.insert(word);
				itd = had.find(word);
				if(itd != had.end()) had.erase(itd);
			}
			else {
				has.erase(word);
				had.insert(word);
			}
		}
		if (game > 1) cout << endl;
		cout << "GAME #" << game << endl;
		cout << "HAS:" << endl;
		for (its = has.begin(); its != has.end(); ++its){
			cout << *(its) << endl;
		}
		cout << endl << "HAD:" << endl;
		for (itd = had.begin(); itd != had.end(); ++itd){
			cout << *(itd) << endl;
		}
		++game;
	}
}