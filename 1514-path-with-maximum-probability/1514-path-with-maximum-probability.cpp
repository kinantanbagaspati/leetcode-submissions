class Solution {
public:
    vector<int> al[12345];
    vector<double> prob[12345];
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        for(int i=0; i<edges.size(); i++){
            al[edges[i][0]].push_back(edges[i][1]);
            prob[edges[i][0]].push_back(succProb[i]);
            al[edges[i][1]].push_back(edges[i][0]);
            prob[edges[i][1]].push_back(succProb[i]);
        }
        double dis[12345];
        bool vis[12345];
        set<pair<double, int>> s;
        for(int i=0; i<n; i++){
            dis[i] = (int) (i == start_node);
            vis[i] = false;
        }
        s.insert({-1, start_node});
        //cout << "masuk" << endl;
        while(!s.empty()){
            //cout << s.size() << endl;
            double curdis = -(*s.begin()).first;
            int node = (*s.begin()).second;
            s.erase(s.begin());
            //cout << curdis << " " << node << endl;
            vis[node] = true;
            for(int i=0; i<al[node].size(); i++){
                int to = al[node][i];
                //cout << "to " << to << endl;
                if(!vis[to] && curdis * prob[node][i] > dis[to]){
                    s.erase({-dis[to], to});
                    dis[to] = curdis * prob[node][i];
                    s.insert({-dis[to], to});
                }
            }
            
        }
        //cout << "return" << endl;
        return dis[end_node];
    }
};