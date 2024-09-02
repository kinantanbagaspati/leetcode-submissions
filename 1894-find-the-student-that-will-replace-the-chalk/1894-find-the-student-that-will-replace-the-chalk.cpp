class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i=0; i<chalk.size(); i++) sum += chalk[i];
        k %= sum;
        int ans;
        for(ans=0; k>=chalk[ans]; ans++) k -= chalk[ans];
        return ans;
    }
};