class Solution {
public:
    int checkRecord(int n) {
        long long mod = 1e9+7, dp[2][2][3];
        dp[0][0][0] = 1;
        dp[0][0][1] = 0;
        dp[0][0][2] = 0;
        dp[0][1][0] = 0;
        dp[0][1][1] = 0;
        dp[0][1][2] = 0;
        for(int i=1; i<=n; i++){
            int j = (i+1)%2;
            dp[i%2][0][0] = (dp[j][0][0]+dp[j][0][1]+dp[j][0][2]) % mod;
            dp[i%2][0][1] = dp[j][0][0];
            dp[i%2][0][2] = dp[j][0][1];
            dp[i%2][1][0] = (dp[j][1][0]+dp[j][1][1]+dp[j][1][2]+dp[i%2][0][0]) % mod;
            dp[i%2][1][1] = dp[j][1][0];
            dp[i%2][1][2] = dp[j][1][1];
        }
        return (
            dp[n%2][0][0]+dp[n%2][0][1]+dp[n%2][0][2]
            +dp[n%2][1][0]+dp[n%2][1][1]+dp[n%2][1][2]
        ) % mod;
    }
};