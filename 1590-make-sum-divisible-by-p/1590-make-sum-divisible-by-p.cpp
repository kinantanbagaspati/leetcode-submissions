class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        map<int, int> m;
        m[0] = 0;
        int sum = 0, tot = 0, ans = nums.size();
        for(int i=0; i<nums.size(); i++) tot = (tot + nums[i]) % p;
        if(tot == 0) return 0;
        for(int i=0; i<nums.size(); i++){
            sum = (sum + nums[i]) % p;
            // kiri + tot - sum = 0
            // kiri = sum - tot
            //cout << i << ": " << sum << " " << (tot + p - sum) % p << endl;
            if(m.count((sum + p - tot) % p) > 0){
                //cout << m[(tot + p - sum) % p] << " sampai " << i+1 << endl;
                ans = min(i+1 - m[(sum + p - tot) % p], ans);
            }
            m[sum] = i+1;
        }
        if(ans == nums.size()) ans = -1;
        return ans;
    }
};