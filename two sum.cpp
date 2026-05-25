#include <bits/stdc++.h>
using namespace std;

vector<int>twosum(vector<int>& nums, int target){
    unordered_map<int , int >mp;

    for(int i =0; i<nums.size(); i++){
        int comp = target - nums[i];
        if(mp.findd[comp]!=mp.end()) return {mp[comp], i};
        mp[nums[i]]=i;
    }
    return{};
}


int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> ans = twoSum(nums, target);
    
    cout << ans[0] << " " << ans[1];
    
    return 0;
}
