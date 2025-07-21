class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sama = 0;
                for(int k=0; k<n; k++){
                    sama += (grid[i][k] == grid[k][j]);
                }
                ans += (sama == n);
            }
        }
        return ans;
    }
};