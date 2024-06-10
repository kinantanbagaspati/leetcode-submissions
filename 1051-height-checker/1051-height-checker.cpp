class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> cpy;
        for(int i=0; i<heights.size(); i++) cpy.push_back(heights[i]);
        sort(cpy.begin(), cpy.end());
        int ans = 0;
        for(int i=0; i<heights.size(); i++) ans += (heights[i] != cpy[i]);
        return ans;
    }
};