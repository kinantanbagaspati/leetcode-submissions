class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool allOne = true;
        for(int i=0; i<nums.size(); i++) allOne = allOne && (nums[i]==1);
        if(allOne) return nums.size()-1;

        int kiri = 0, kanan = 0, n = nums.size();
        int zeros = 0, ans = 0, k = 1;
        while(kanan < n){
            if(zeros <= k){
                ans = max(kanan-kiri, ans);
                zeros += (nums[kanan] == 0);
                kanan++;
            }else if(zeros > k){
                zeros -= (nums[kiri] == 0);
                kiri++;
            }
        }
        if(zeros <= k) ans = max(kanan-kiri, ans);
        return ans-1;
    }
};