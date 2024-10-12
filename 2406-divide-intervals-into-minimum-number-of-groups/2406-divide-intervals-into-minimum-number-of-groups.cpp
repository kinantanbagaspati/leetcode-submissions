class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> v;
        for(int i=0; i<intervals.size(); i++){
            v.push_back({intervals[i][0], 1});
            v.push_back({intervals[i][1]+1, -1});
        }
        sort(v.begin(), v.end());
        int ans = 0, cur = 0;
        for(int i=0; i<v.size(); i++){
            cur += v[i].second;
            ans = max(ans, cur);
        }
        return ans;
    }
};