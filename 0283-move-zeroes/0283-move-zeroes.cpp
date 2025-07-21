class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]){
                swap(nums[cur], nums[i]); cur++;
            }
        }
    }
};