class Solution {
public:
    int dis[16][16];
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j}); dis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            pair<int, int> h = q.front(); q.pop();
            if(h.first > 0 && grid[h.first-1][h.second]==1 && dis[h.first-1][h.second]==0){
                dis[h.first-1][h.second] = dis[h.first][h.second] + 1;
                q.push({h.first-1, h.second});
            }
            if(h.first < n-1 && grid[h.first+1][h.second]==1 && dis[h.first+1][h.second]==0){
                dis[h.first+1][h.second] = dis[h.first][h.second] + 1;
                q.push({h.first+1, h.second});
            }
            if(h.second > 0 && grid[h.first][h.second-1]==1 && dis[h.first][h.second-1]==0){
                dis[h.first][h.second-1] = dis[h.first][h.second] + 1;
                q.push({h.first, h.second-1});
            }
            if(h.second < m-1 && grid[h.first][h.second+1]==1 && dis[h.first][h.second+1]==0){
                dis[h.first][h.second+1] = dis[h.first][h.second] + 1;
                q.push({h.first, h.second+1});
            }
        }
        int ans = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0){
                    if(dis[i][j] == 0) return -1;
                    ans = max(dis[i][j], ans);
                }
            }
        }
        return ans-1;
    }
};