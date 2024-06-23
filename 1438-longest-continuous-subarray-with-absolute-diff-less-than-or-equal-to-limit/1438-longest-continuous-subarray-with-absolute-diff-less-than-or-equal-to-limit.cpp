class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0, lo = 0, hi = 0;
        multiset<int> pos, neg;
        while(hi < nums.size()){
            if(hi > lo && -*(neg.begin())-*(pos.begin()) > limit){
                neg.erase(neg.lower_bound(-nums[lo]));
                pos.erase(pos.lower_bound(nums[lo]));
                lo++;
            }else{
                neg.insert(-nums[hi]);
                pos.insert(nums[hi]);
                hi++;
            }
            if(-*(neg.begin())-*(pos.begin()) <= limit){
                //cout << lo << "-" << hi << endl;
                ans = max(hi-lo, ans);
            }
        }
        return ans;
    }
};