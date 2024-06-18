class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int> > pii;
        for(int i=0; i<profit.size(); i++) pii.push_back({difficulty[i], profit[i]});
        sort(pii.begin(), pii.end());
        sort(worker.begin(), worker.end());
        int j=0, ans=0, cur=0;
        for(int i=0; i<worker.size(); i++){
            while(j<pii.size() && pii[j].first<=worker[i]){
                cur = max(pii[j].second, cur); j++;
            }
            ans += cur;
        }
        return ans;
    }
};