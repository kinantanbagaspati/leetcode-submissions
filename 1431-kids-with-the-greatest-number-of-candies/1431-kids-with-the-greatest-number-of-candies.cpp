class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = candies[0];
        for(int i=1; i<candies.size(); i++) mx = max(candies[i], mx);
        vector<bool> ans;
        for(int i=0; i<candies.size(); i++) ans.push_back(candies[i] + extraCandies >= mx);
        return ans;
    }
};