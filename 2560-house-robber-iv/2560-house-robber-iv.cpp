class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        int lo = 0, hi = (1<<30);
        while(hi-lo > 1){
            int mid = (lo+hi)/2;
            vector<int> dp;
            dp.push_back(nums[0] <= mid); 
            dp.push_back(nums[1] <= mid); dp[1] = max(dp[0], dp[1]);
            for(int i=2; i<nums.size(); i++) dp.push_back(max(dp[i-1], dp[i-2]+(nums[i] <= mid)));
            if(dp[nums.size()-1] < k){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        return hi;
    }
};