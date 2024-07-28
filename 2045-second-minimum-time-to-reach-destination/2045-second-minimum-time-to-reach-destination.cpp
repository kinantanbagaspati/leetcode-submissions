class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        //change *= (time+change-1)/change;
        vector<int> al[n+1], q;
        for(int i=0; i<edges.size(); i++){
            al[edges[i][0]].push_back(edges[i][1]);
            al[edges[i][1]].push_back(edges[i][0]);
        }
        int dis[n+1][2], vis[n+1];
        for(int i=1; i<=n; i++){
            dis[i][0] = 1e9; dis[i][1] = 1e9; vis[i] = 0;
        }
        dis[1][0] = 0; q.push_back(1);
        for(int i=0; i<n*2; i++){
            //cout << "queue";
            //for(int j=i; j<q.size(); j++) cout << " " << q[j];
            //cout << endl;
            for(int j=0; j<al[q[i]].size(); j++){
                int to = al[q[i]][j], cur = dis[q[i]][vis[q[i]]];
                //cout << "dis " << dis[q[i]][0] << " " << dis[q[i]][1] << endl;
                //cout << cur << ", " << change << endl;
                if(cur / change % 2) cur = cur / change * change + change;
                //cout << q[i] << "->" << to << " " << cur << "->" << cur+time << endl;
                if(dis[to][0] == 1e9){
                    dis[to][0] = cur+time;
                    q.push_back(to);
                }else if(dis[to][1] == 1e9 && dis[to][0] != cur + time){
                    dis[to][1] = cur+time;
                    q.push_back(to);
                }
            }
            vis[q[i]]++;
        }
        //for(int i=1; i<=n; i++) cout << dis[i][0] << " " << dis[i][1] << endl;
        return dis[n][1];  
    }
};