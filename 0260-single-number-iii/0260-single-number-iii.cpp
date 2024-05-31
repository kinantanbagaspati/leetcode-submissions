class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> s;
        for(int i=0; i<nums.size(); i++){
            if(s.count(nums[i])){
                s.erase(nums[i]);
            }else{
                s.insert(nums[i]);
            }
        }
        vector<int> ans;
        while(s.size() > 0){
            ans.push_back(*(s.begin()));
            s.erase(s.begin());
        }
        return ans;
    }
};