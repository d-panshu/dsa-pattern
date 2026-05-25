#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {

    int insertPos = 0;

    // Move all non-zero elements forward
    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] != 0) {

            swap(nums[i], nums[insertPos]);

            insertPos++;
        }
    }
}

int main() {

    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}