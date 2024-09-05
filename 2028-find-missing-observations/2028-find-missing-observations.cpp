class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        mean *= n + rolls.size();
        for(int i=0; i<rolls.size(); i++) mean -= rolls[i];
        vector<int> ans;
        if(mean < n || mean > n*6) return ans;
        for(int i=0; i<n; i++) ans.push_back(mean/n + (i < mean%n));
        return ans;
    }
};