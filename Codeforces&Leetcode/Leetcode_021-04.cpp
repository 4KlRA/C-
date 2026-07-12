class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> unique(s.begin(), s.end());
        return unique.size();
    }
};