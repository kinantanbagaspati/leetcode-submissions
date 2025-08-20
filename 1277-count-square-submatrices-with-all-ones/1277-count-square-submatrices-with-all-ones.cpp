class Solution {
public:
    int dp[321][321];
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<321; i++){
            dp[0][i] = 0; dp[i][0];
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + matrix[i][j];
                for(int k=0; k<=min(i, j); k++){
                    ans += (dp[i+1][j+1] - dp[i-k][j+1] - dp[i+1][j-k] + dp[i-k][j-k] == (k+1)*(k+1));
                }
                //cout << i << " " << j << ": " << ans << endl;
            }
        }
        return ans;
    }
};