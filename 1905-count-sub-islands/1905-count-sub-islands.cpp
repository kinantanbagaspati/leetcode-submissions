class Solution {
public:
    bool vis[512][512];
    int n, m;
    bool isSubset(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        //cout << "Masuk" << endl;
        vis[i][j] = true;
        bool res = grid1[i][j];
        if(i>0 && grid2[i-1][j] && !vis[i-1][j]) res = isSubset(grid1, grid2, i-1, j) && res;
        if(j>0 && grid2[i][j-1] && !vis[i][j-1]) res = isSubset(grid1, grid2, i, j-1) && res;
        if(i<n-1 && grid2[i+1][j] && !vis[i+1][j]) res = isSubset(grid1, grid2, i+1, j) && res;
        //cout << i << " " << j << " " << grid2[i][j+1] << " " << vis[i][j+1] << endl;
        //cout << (j<m-1 && grid2[i][j+1] && !vis[i][j+1]) << endl;
        if(j<m-1 && grid2[i][j+1] && !vis[i][j+1]) res = isSubset(grid1, grid2, i, j+1) && res;
        //cout << i << " " << j << " returns " << res << endl;
        return res;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        //cout << "n m " << n << " " << m << "vs" << grid1.size() << " " << grid1[0].size() << endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) vis[i][j] = false;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid2[i][j]){
                    ans += isSubset(grid1, grid2, i, j);
                    //cout << i << "," << j << " " << ans << endl;
                }
            }
        }
        /*for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cout << vis[i][j];
            cout << endl;
        }*/
        return ans;
    }
};