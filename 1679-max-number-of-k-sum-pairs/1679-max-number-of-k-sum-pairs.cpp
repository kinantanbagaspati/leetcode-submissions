class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size(), kiri = 0, kanan = n-1;
        sort(nums.begin(), nums.end());
        int ans = 0;
        while(kiri<kanan){
            if(nums[kiri] + nums[kanan] < k){
                kiri++;
            }else if(nums[kiri] + nums[kanan] > k){
                kanan--;
            }else{
                ans++; kiri++; kanan--;
            }
        }
        return ans;
    }
};