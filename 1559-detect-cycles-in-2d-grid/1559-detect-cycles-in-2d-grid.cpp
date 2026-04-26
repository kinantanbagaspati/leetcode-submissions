class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;
    vector<vector<char>> grd;
    bool dfs(int x, int y, char frm){
        vis[x][y] = true;
        if(frm!='u' && x>0 && grd[x-1][y]==grd[x][y]){
            if(vis[x-1][y]) return true;
            if(dfs(x-1, y, 'd')) return true;
        }
        if(frm!='l' && y>0 && grd[x][y-1]==grd[x][y]){
            if(vis[x][y-1]) return true;
            if(dfs(x, y-1, 'r')) return true;
        }
        if(frm!='d' && x+1<n && grd[x+1][y]==grd[x][y]){
            if(vis[x+1][y]) return true;
            if(dfs(x+1, y, 'u')) return true;
        }
        if(frm!='r' && y+1<m && grd[x][y+1]==grd[x][y]){
            if(vis[x][y+1]) return true;
            if(dfs(x, y+1, 'l')) return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(); m = grid[0].size();
        vector<bool> mpty;
        vector<char> empty;
        for(int i=0; i<n; i++){
            vis.push_back(mpty);
            grd.push_back(empty);
            for(int j=0; j<m; j++){
                vis[i].push_back(false);
                grd[i].push_back(grid[i][j]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    if(dfs(i, j, ' ')) return true;
                }
            }
        }
        return false;
    }
};