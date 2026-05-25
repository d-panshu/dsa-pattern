#include <bits/stdc++.h>
using namespace std;


int maxsubarray(vector<int>&nums){
    int cuurrent_sum = nums[0];
    int max_sum= nums[0];

    for (int i=1; i<nums.size(); i++){
        cuurrent_sum = max(nums[i], cuurrent_sum + nums[i]);
        max_sum = max(max_sum, cuurrent_sum);
    }

    return max_sum;
}

int main() {

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxsubarray(nums);

    return 0;
}