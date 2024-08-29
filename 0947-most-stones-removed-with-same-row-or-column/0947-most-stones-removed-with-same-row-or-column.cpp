class Solution {
public:
    vector<int> perrow[12345], percol[12345];
    bool vis[1024];
    int dfs(vector<vector<int>>& stones, int node){
        vis[node] = true;
        int ans = 1;
        for(int i=0; i<perrow[stones[node][0]].size(); i++){
            int to = perrow[stones[node][0]][i];
            if(to != node && !vis[to]) ans += dfs(stones, to);
        }
        for(int i=0; i<percol[stones[node][1]].size(); i++){
            int to = percol[stones[node][1]][i];
            if(to != node && !vis[to]) ans += dfs(stones, to);
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        for(int i=0; i<stones.size(); i++){
            perrow[stones[i][0]].push_back(i);
            percol[stones[i][1]].push_back(i);
        }
        int ans = 0;
        for(int i=0; i<stones.size(); i++){
            if(!vis[i]) ans = ans + dfs(stones, i)-1;
        }
        return ans;
    }
};