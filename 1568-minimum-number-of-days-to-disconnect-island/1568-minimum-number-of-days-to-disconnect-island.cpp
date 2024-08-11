class Solution {
public:
    int parity = 1;
    void dfs(vector<vector<int>>& grid, int i, int j){
        grid[i][j] = parity + 1;
        if(i > 0 && grid[i-1][j] != parity + 1) dfs(grid, i-1, j);
        if(j > 0 && grid[i][j-1] != parity + 1) dfs(grid, i, j-1);
        if(i < grid.size()-1 && grid[i+1][j] != parity + 1) dfs(grid, i+1, j);
        if(j < grid[i].size()-1 && grid[i][j+1] != parity + 1) dfs(grid, i, j+1);
    }

    int minDays(vector<vector<int>>& grid) {
        int island = 0, n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != parity + 1){
                    island++; dfs(grid, i, j);
                }
            }
        }
        if(island != 1) return 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == parity + 1){
                    grid[i][j] = 0;
                    parity = !parity;
                    island = 0;
                    for(int ii=0; ii<n; ii++){
                        for(int jj=0; jj<n; jj++){
                            if(grid[ii][jj] != parity + 1){
                                island++; dfs(grid, ii, jj);
                            }
                        }
                    }
                    if(island != 1) return 1;
                    grid[i][j] = parity + 1;
                }
            }
        }
        return 2;    
    }
};