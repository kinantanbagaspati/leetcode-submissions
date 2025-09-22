class Solution {
public:
    vector<pair<int, bool>> al[1<<16];
    int dfs(int node, int from){
        int ret = 0;
        for(int i=0; i<al[node].size(); i++){
            int to = al[node][i].first;
            if(from != to){
                ret += al[node][i].second;
                //cout << node << "-" << to << " " << al[node][i].second << endl;
                ret += dfs(to, node);
            }
        }
        //cout << "dfs " << node << " from " << from << " return " << ret << endl;
        return ret;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for(int i=0; i<connections.size(); i++){
            al[connections[i][0]].push_back({connections[i][1], 1});
            al[connections[i][1]].push_back({connections[i][0], 0});
        }
        return dfs(0, -1);
    }
};