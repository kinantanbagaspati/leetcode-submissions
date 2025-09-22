class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int prefsum[1<<17], n = spells.size();
        for(int i=0; i<(1<<17); i++) prefsum[i] = 0;
        for(int i=0; i<potions.size(); i++) prefsum[potions[i]]++;
        for(int i=(1<<17)-2; i>=0; i--) prefsum[i] += prefsum[i+1];
        vector<int> ans;
        for(int i=0; i<n; i++){
            long long idx = (success+spells[i]-1)/spells[i];
            if(idx < (1<<17)){
                ans.push_back(prefsum[idx]);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};