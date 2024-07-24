class Solution {
public:

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int unmap[10], n = nums.size();
        for(int i=0; i<10; i++) unmap[mapping[i]] = i;
        pair<int, int> srt[n];
        for(int i=0; i<n; i++){
            srt[i].first = 0; srt[i].second = i;
            for(int j=1; j<1e9 && j <= nums[i]; j*=10){
                srt[i].first += mapping[nums[i] / j % 10] * j;
                //cout << j << " " << srt[i].first << endl;
            }
            //cout << srt[i].first << " " << srt[i].second << endl;
        }
        sort(srt, srt + n);
        vector<int> ans;
        for(int i=0; i<n; i++) ans.push_back(nums[srt[i].second]);
        return ans;
    }
};