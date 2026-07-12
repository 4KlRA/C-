class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> num(nums.begin(), nums.end());
        int a = 1;
        while(num.find(a) != num.end()){
            a++;
        }
        return a;
    }
};