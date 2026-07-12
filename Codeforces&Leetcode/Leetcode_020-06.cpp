class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        for(auto& rows : matrix) {
            int sum = 0;
            for(int element : rows) {
                if(element == 1) sum++;
            }
            ans.push_back(sum);
        }
         return ans;
    }
};