class Solution {
public:
    int minDifference(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 4) return 0;
        sort(nums.begin(), nums.end());
        return min({nums[sz-4]-nums[0], nums[sz-3]-nums[1], nums[sz-2]-nums[2], nums[sz-1]-nums[3]});
    }
};