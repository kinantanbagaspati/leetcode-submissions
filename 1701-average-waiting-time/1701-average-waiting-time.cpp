class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long sum = 0, cur = 0;
        for(int i=0; i<customers.size(); i++){
            cur = max((long long)customers[i][0], cur);
            sum += cur + customers[i][1] - customers[i][0];
            cur += customers[i][1];
        }
        return (double) sum / customers.size();
    }
};