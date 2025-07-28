class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0, cnt = 0, n = nums.size();
        for(int i=0; i<(1<<n); i++){
            int cpy = i, cur = 0;
            for(int j=0; j<n; j++){
                if(cpy%2) cur = (cur | nums[j]);
                cpy /= 2;
            }
            if(cur > mx){
                mx = cur; cnt = 1;
            }else if(cur == mx){
                cnt++;
            }
        }
        return cnt;
    }
};