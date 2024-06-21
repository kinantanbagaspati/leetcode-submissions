class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int dp[grumpy.size()+1], ans=0;
        dp[0] = 0;
        for(int i=0; i<grumpy.size(); i++){
            dp[i+1] = dp[i]+customers[i]*grumpy[i];
            ans += customers[i]*(1-grumpy[i]);
        }
        int cur=0;
        for(int i=minutes; i<=grumpy.size(); i++){
            cur = max(dp[i]-dp[i-minutes], cur);
        }
        return ans+cur;
    }
};