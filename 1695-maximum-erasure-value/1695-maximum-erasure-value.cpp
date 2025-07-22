class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int kiri = 0, kanan = 0, cur = 0, ans = 0;
        set<int> s;
        while(kanan < nums.size()){
            if(s.count(nums[kanan])){
                cur -= nums[kiri];
                s.erase(nums[kiri]);
                kiri++;
            }else{
                cur += nums[kanan];
                ans = max(cur, ans);
                s.insert(nums[kanan]);
                kanan++;
            }
        }
        return ans;
    }
};