class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        long long mul = 1;
        int num0 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]){
                mul *= nums[i];
            }else{
                num0++;
            }
            ans.push_back(0);
        }
        if(num0 > 1){
            return ans;
        }else if(num0){
            for(int i=0; i<nums.size(); i++) if(nums[i]==0) ans[i] = mul;
            return ans;
        }else{
            for(int i=0; i<nums.size(); i++) ans[i] = mul/nums[i];
            return ans;
        }
    }
};