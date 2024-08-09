class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=1; i<grid.size()-1; i++){
            for(int j=1; j<grid[0].size()-1; j++){
                int sum = 0;
                for(int k=-1; k<2; k++){
                    for(int m=-1; m<2; m++) sum += grid[i+k][j+m]*grid[i+k][j+m];
                }
                ans += (sum == 285
                    && grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1] == 15
                    && grid[i][j-1]+grid[i][j]+grid[i][j+1] == 15
                    && grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1] == 15
                    && grid[i-1][j-1]+grid[i][j-1]+grid[i+1][j-1] == 15
                    && grid[i-1][j]+grid[i][j]+grid[i+1][j] == 15
                    && grid[i-1][j+1]+grid[i][j+1]+grid[i+1][j+1] == 15
                    && grid[i-1][j-1]+grid[i][j]+grid[i+1][j+1] == 15
                    && grid[i-1][j+1]+grid[i][j]+grid[i+1][j-1] == 15
                );
            }
        }
        return ans;
    }
};