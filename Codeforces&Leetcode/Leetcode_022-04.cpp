class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allow(allowed.begin(), allowed.end());
        int count = 0;
        for(auto i : words) {
            bool valid = true;
            for(auto j : i) {
                if(allow.find(j) == allow.end()) {
                    valid = false;
                    break;
                }
            }
            if(valid) count++;
        }
        return count;
    }
};