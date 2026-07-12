#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums(4);
    cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];

    sort(nums.begin(), nums.end());

    int S = nums[3];

    cout << S - nums[2] << " " << S - nums[1] << " " << S - nums[0] << "\n";

    return 0;
}