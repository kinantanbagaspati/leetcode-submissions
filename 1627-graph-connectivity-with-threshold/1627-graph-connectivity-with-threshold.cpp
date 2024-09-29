const int maxn = 12345;
class Solution {
public:
    vector<int> al[maxn*2]; // maxn+i phantom node -i
    int warna[maxn*2], nbwarna = 0;
    void dfs(int node){
        warna[node] = nbwarna;
        for(int i=0; i<al[node].size(); i++){
            int to = al[node][i];
            if(warna[to] == 0){
                dfs(to);
            }
        }
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        // bikin graph
        for(int i=threshold+1; i<=n; i++){
            // proses manaaja yg konek ke phantom node -i
            // iterate x habis dibagi i
            for(int j=i; j<=n; j+=i){
                // x sambungkan dengan -i
                al[j].push_back(maxn+i);
                al[maxn+i].push_back(j);
            }
        }
        for(int i=0; i<maxn*2; i++) warna[i] = 0;
        for(int i=0; i<maxn*2; i++){
            if(warna[i] == 0){
                nbwarna++;
                dfs(i); // ngewarnain semua node yg bisa diraih dengan warna baru yg sama
            }
        }
        vector<bool> ans;
        for(int i=0; i<queries.size(); i++){
            ans.push_back(warna[queries[i][0]] == warna[queries[i][1]]);
        }
        return ans;
    }
};