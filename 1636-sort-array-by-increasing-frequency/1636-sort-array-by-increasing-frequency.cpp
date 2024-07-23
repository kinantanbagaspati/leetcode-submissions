class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int> > srt;
        srt.push_back({1, -nums[0]});
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                srt.push_back({1, -nums[i]});
            }else{
                srt[srt.size()-1].first++;
            }
        }
        sort(srt.begin(), srt.end());
        vector<int> ans;
        for(int i=0; i<srt.size(); i++){
            while(srt[i].first--) ans.push_back(-srt[i].second);
        }
        return ans;
    }
};