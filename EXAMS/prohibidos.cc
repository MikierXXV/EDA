#include <iostream>
#include <vector>
using namespace std;


bool multiple(const vector<int>& nums, int s){
    for (int i = 0; i < nums.size(); ++i){
        if(s % nums[i] == 0) return true;
    }
    return false;
}

void escriu(const vector<int>& sol, int n){
    for (int i = 0; i < n; ++i) cout << sol[i];
    cout << endl;
}

void back_track(int i, int n, int m, const vector<int>& nums, vector<int>& sol, vector<bool>& vis, int num, int suma){
    if(i == n) escriu(sol, n);
    else if(num < 10){
        if(not vis[num]){
            if(i == 0){
                for (int j = 0; j < 10; ++j){
                    if(not multiple(nums, suma+j)){
                        sol.push_back(j);
                        back_track(i+1, n, m, nums, sol, vis, num+1, suma+j);
                        sol.pop_back();
                    }
                }
            }
            else{
                for (int j = 0; j < 10; ++j){
                    if(not multiple(nums, suma*10+j)){
                        sol.push_back(j);
                        back_track(i+1, n, m, nums, sol, vis, num+1, suma*10+j);
                        sol.pop_back();
                    }
                }
            }
        }

    }
}


int main(){

    int n, m;
    while(cin >> n >> m){
        vector<int> nums(m);
        for (int i = 0; i < m; ++i) cin >> nums[i];
        vector<int> sol;
        vector<bool> vis(9, false);
        back_track(0, n, m, nums, sol, vis, 0, 0);
        cout << string(10, '-') << endl;

    }
}

