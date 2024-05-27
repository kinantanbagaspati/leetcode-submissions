class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] >= nums.size()) return nums.size();
        for(int i=1; i<nums.size(); i++){
            if(nums[nums.size()-i-1] < i && i <= nums[nums.size()-i]){
                return i;
            }
        }
        return -1;
    }
};