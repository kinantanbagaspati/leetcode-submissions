class Solution {
public:
    vector<int> al[4096];
    bool vis[4096];
    void edge(int a, int b){
        al[a].push_back(b); al[b].push_back(a);
    }
    void dfs(int a){
        vis[a] = true;
        for(int i=0; i<al[a].size(); i++){
            if(!vis[al[a][i]]) dfs(al[a][i]);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int id = i*n+j;
                for(int k=0; k<4; k++) vis[id*4+k] = false;
                if(i>0) edge(id*4, (id-n)*4+2);
                if(j>0) edge(id*4+3, (id-1)*4+1);
                if(grid[i][j] != '/'){
                    edge(id*4, id*4+1); edge(id*4+2, id*4+3);
                }
                if(grid[i][j] != '\\'){
                    edge(id*4, id*4+3); edge(id*4+1, id*4+2);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n*n*4; i++){
            if(!vis[i]){
                dfs(i); ans++;
            }
        }
        return ans;
    }
};