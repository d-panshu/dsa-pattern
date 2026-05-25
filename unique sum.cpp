#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findPairs(vector<int>& nums, int target) {

    unordered_set<int> visited;

    set<pair<int, int>> uniquePairs;

    for (int num : nums) {

        int complement = target - num;

        // If complement already seen
        if (visited.find(complement) != visited.end()) {

            int a = min(num, complement);
            int b = max(num, complement);

            uniquePairs.insert({a, b});
        }

        visited.insert(num);
    }

    vector<pair<int, int>> result;

    for (auto pairVal : uniquePairs) {
        result.push_back(pairVal);
    }

    return result;
}

int main() {

    vector<int> nums = {1,2,3,2,4,5,3};

    int target = 5;

    vector<pair<int,int>> ans = findPairs(nums, target);

    for (auto p : ans) {
        cout << "(" << p.first << "," << p.second << ")" << endl;
    }

    return 0;
}