class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long fw[32][32];
        for(int i=0; i<32; i++){
            for(int j=0; j<32; j++) fw[i][j] = (i==j) ? 0 : 1e18;
        }
        for(int i=0; i<cost.size(); i++){
            fw[original[i]-'a'][changed[i]-'a'] = min(fw[original[i]-'a'][changed[i]-'a'], (long long)cost[i]);
        }
        for(int i=0; i<32; i++){
            for(int j=0; j<32; j++){
                for(int k=0; k<32; k++){
                    fw[j][k] = min(fw[j][i]+fw[i][k], fw[j][k]);
                }
            }
        }
        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            if(fw[source[i]-'a'][target[i]-'a'] == 1e18){
                return -1;
            }else{
                ans += fw[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};