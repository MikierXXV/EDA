#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& sub, const vector<int>& nums){
	cout << "{";
	bool primer = true;
	for (int i = 0; i < sub.size(); ++i){
		if (sub[i] != 0){
			if (primer) primer = false;
			else if (not primer) cout << ", ";
			cout << nums[i];
		}
	}
	cout << "}" << endl;
}

void back_track(int i, int s, int n, const vector<int>& nums, vector<int>& sub, int total, int suma){
	if(i == n) {
		if(suma == s) escriu(sub, nums);
	}
	else if (suma <= s and suma + total >= s){
		sub[i] = 1;
		back_track(i+1, s, n, nums, sub, total-nums[i], suma+nums[i]);
		sub[i] = 0;
		back_track(i+1, s, n, nums, sub, total-nums[i], suma);
	}
}

int main(){
	int s, n;
	cin >> s >> n;
	vector<int> nums(n);
	int total = 0;
	for (int i = 0; i < n; ++i){
		cin >> nums[i];
		total += nums[i];
	} 
	vector<int> sub(n);

	back_track(0, s, n, nums, sub, total, 0);
}