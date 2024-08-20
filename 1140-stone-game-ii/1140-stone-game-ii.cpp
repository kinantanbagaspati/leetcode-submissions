class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size(), dp[n+1][n+1], sufsum[n+1];
        sufsum[n] = 0;
        for(int i=1; i<=n; i++){
            dp[n][i] = 0;
            sufsum[n-i] = sufsum[n-i+1] + piles[n-i];
        }
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=n; j++){
                int sum = 0;
                dp[i][j] = -1e9;
                for(int k=1; k<=j*2 && i+k<=n; k++){
                    sum += piles[i+k-1];
                    dp[i][j] = max(sum + sufsum[i+k] - dp[i+k][max(j,k)], dp[i][j]);
                }
            }
        }
        return dp[0][1];
    }
};