class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long m = points.size(), n = points[0].size(), cur[3][n];
        for(int i=0; i<n; i++) cur[0][i] = points[0][i];
        for(int i=1; i<m; i++){
            cur[1][0] = cur[0][0];
            for(int j=1; j<n; j++) cur[1][j] = max(cur[1][j-1], cur[0][j] + j);
            cur[2][n-1] = cur[0][n-1] - (n-1);
            for(int j=n-2; j>=0; j--) cur[2][j] = max(cur[2][j+1], cur[0][j] - j);
            
            for(int j=0; j<n; j++) cur[0][j] = points[i][j] + max(cur[1][j]-j, cur[2][j]+j);
        }
        long long ans = cur[0][0];
        for(int i=1; i<n; i++) ans = max(cur[0][i], ans);
        return ans;
    }
};