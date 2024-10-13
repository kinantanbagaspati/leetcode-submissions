class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        ans.push_back(-1e9); ans.push_back(1e9);
        vector<pair<int, int>> srt;
        for(int i=0; i<3; i++){
            for(int j=0; j<nums[i].size(); j++){
                srt.push_back({nums[i][j], i});
            }
        }
        int freq[3] = {0, 0, 0}, lo = 0, hi = 0;
        sort(srt.begin(), srt.end());
        while(lo < srt.size()){
            while(hi < srt.size() && (freq[0] == 0 || freq[1] == 0 || freq[2] == 0)){
                freq[srt[hi].second]++; hi++;
            }
            if(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                if(srt[hi-1].first - srt[lo].first < ans[1] - ans[0]){
                    ans[0] = srt[lo].first;
                    ans[1] = srt[hi-1].first;
                }
            }
            freq[srt[lo].second]--; lo++;
        }
        return ans;
    }
};