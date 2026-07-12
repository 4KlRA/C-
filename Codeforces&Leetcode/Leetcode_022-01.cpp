class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        for(int i : order) {
            for(int j : friends) {
                if(i == j) ans.push_back(i);
            }
        }
        return ans;
    }
};