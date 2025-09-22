class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[128];
        for(int i=0; i<128; i++) freq[i] = 0;
        for(int i=0; i<nums.size(); i++) freq[nums[i]]++;
        int mx = freq[0], ans = 0;
        for(int i=1; i<128; i++) mx = max(freq[i], mx);
        for(int i=0; i<128; i++) ans += freq[i] * (freq[i] == mx);
        return ans;
    }
};