class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(int i=0; i<logs.size(); i++){
            if(logs[i][0] != '.'){
                ans ++;
            }else if(logs[i][1] == '.'){
                ans = max(ans-1, 0);
            }
        }
        return ans;
    }
};