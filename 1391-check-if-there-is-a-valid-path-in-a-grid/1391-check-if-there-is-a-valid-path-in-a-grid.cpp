class Solution {
public:
    vector<pair<int, int>> adjl[1024][1024];
    int m, n;
    bool vis[1024][1024];
    void dfs(int x, int y){
        vis[x][y] = true;
        for(int i=0; i<adjl[x][y].size(); i++){
            pair<int, int> to = adjl[x][y][i];
            //cout << "to " << to.first << " " << to.second << endl;
            if(!vis[to.first][to.second]) dfs(to.first, to.second);
        }
    }
    void join(pair<int, int> a, pair<int, int> b){
        adjl[a.first][a.second].push_back(b); adjl[b.first][b.second].push_back(a);
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        for(int x=0; x<m*2; x++) for(int y=0; y<n*2; y++) vis[x][y] = false;
        for(int x=1; x<m*2; x+=2){
            for(int y=1; y<n*2; y+=2){
                if(grid[x/2][y/2]==1){
                    join({x,y}, {x,y-1}); join({x,y}, {x,y+1});
                }else if(grid[x/2][y/2]==2){
                    join({x,y}, {x-1,y}); join({x,y}, {x+1,y});
                }else if(grid[x/2][y/2]==3){
                    join({x,y}, {x,y-1}); join({x,y}, {x+1,y});
                }else if(grid[x/2][y/2]==4){
                    join({x,y}, {x,y+1}); join({x,y}, {x+1,y});
                }else if(grid[x/2][y/2]==5){
                    join({x,y}, {x,y-1}); join({x,y}, {x-1,y});
                }else if(grid[x/2][y/2]==6){
                    join({x,y}, {x,y+1}); join({x,y}, {x-1,y});
                }
            }
        }
        dfs(1,1);
        return vis[m*2-1][n*2-1];
    }
};