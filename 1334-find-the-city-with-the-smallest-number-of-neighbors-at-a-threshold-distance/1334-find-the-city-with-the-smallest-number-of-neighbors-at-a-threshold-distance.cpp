class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dis[128][128];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j){
                    dis[i][j] = 1e9;
                }else{
                    dis[i][j] = 0;
                }
            }
        }
        for(int i=0; i<edges.size(); i++){
            dis[edges[i][0]][edges[i][1]] = min(dis[edges[i][0]][edges[i][1]], edges[i][2]);
            dis[edges[i][1]][edges[i][0]] = min(dis[edges[i][1]][edges[i][0]], edges[i][2]);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    dis[j][k] = min(dis[j][i] + dis[i][k], dis[j][k]);
                }
            }
        }
        int nbcit = n, ans = 0;
        for(int i=0; i<n; i++){
            int cur = 0;
            for(int j=0; j<n; j++) cur += (dis[i][j] <= distanceThreshold);
            if(cur <= nbcit){
                ans = i; nbcit = cur;
            }
        }
        return ans;
    }
};