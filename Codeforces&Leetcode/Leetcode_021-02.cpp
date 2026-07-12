class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> num = nums;
        for(int i : views::reverse(nums)) num.push_back(i);
        return num;
    }
};