class Solution {
public:
    map<int, int> nb, sum;
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), cur = 0, ans = 0;
        nb[0] = 1;
        sum[0] = 0;
        for(int i=0; i<n; i++){
            cur ^= arr[i];
            ans += nb[cur] * (i+1) - (sum[cur] + nb[cur]);
            nb[cur]++;
            sum[cur] += (i+1);
        }
        return ans;
    }
};