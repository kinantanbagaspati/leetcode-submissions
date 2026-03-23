class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long mod = 1e9+7;
        pair<long long, long long> dp[n][m];
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) dp[i][j] = {1,-1};
        dp[0][0].first = min(grid[0][0], 1);
        dp[0][0].second = max(grid[0][0], -1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i>0){
                    dp[i][j].first = min({
                        dp[i-1][j].second * grid[i][j],
                        dp[i-1][j].first * grid[i][j],
                        dp[i][j].first
                    });
                    dp[i][j].second = max({
                        dp[i-1][j].second * grid[i][j],
                        dp[i-1][j].first * grid[i][j],
                        dp[i][j].second
                    });
                }
                if(j>0){
                    dp[i][j].first = min({
                        dp[i][j-1].second * grid[i][j],
                        dp[i][j-1].first * grid[i][j],
                        dp[i][j].first
                    });
                    dp[i][j].second = max({
                        dp[i][j-1].second * grid[i][j],
                        dp[i][j-1].first * grid[i][j],
                        dp[i][j].second
                    });
                }
            }
        }
        return dp[n-1][m-1].second % mod;
    }
};