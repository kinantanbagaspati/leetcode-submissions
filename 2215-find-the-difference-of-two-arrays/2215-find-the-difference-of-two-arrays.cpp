class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        vector<int> kosong;
        set<int> s1, s2, ss1, ss2;
        for(int i=0; i<nums1.size(); i++) s1.insert(nums1[i]);
        for(int i=0; i<nums2.size(); i++) s2.insert(nums2[i]);
        for(int i=0; i<nums1.size(); i++) if(s2.count(nums1[i])==0) ss1.insert(nums1[i]);
        for(int i=0; i<nums2.size(); i++) if(s1.count(nums2[i])==0) ss2.insert(nums2[i]);
        ans.push_back(kosong);
        while(ss1.size()){
            ans[0].push_back(*ss1.begin()); ss1.erase(ss1.begin());
        }
        ans.push_back(kosong);
        while(ss2.size()){
            ans[1].push_back(*ss2.begin()); ss2.erase(ss2.begin());
        }
        return ans;
    }
};