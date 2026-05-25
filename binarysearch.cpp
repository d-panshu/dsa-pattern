#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        // Target found
        if (nums[mid] == target) {
            return mid;
        }

        // Left half sorted
        if (nums[left] <= nums[mid]) {

            // Target inside left sorted half
            if (target >= nums[left] &&
                target < nums[mid]) {

                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        // Right half sorted
        else {

            // Target inside right sorted half
            if (target > nums[mid] &&
                target <= nums[right]) {

                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    vector<int> nums = {4,5,6,7,0,1,2};

    int target = 0;

    cout << search(nums, target);

    return 0;
}