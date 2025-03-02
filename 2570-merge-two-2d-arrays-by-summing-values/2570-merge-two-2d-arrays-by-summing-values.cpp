class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        vector<int> ad; ad.push_back(0); ad.push_back(0);
        int idx = 0;
        for(int i=0; i<nums1.size(); i++){
            while(idx < nums2.size() && nums2[idx][0] < nums1[i][0]){
                ad[0] = nums2[idx][0]; ad[1] = nums2[idx][1];
                ans.push_back(ad);
                idx++;
            }
            if(idx < nums2.size() && nums1[i][0] == nums2[idx][0]){
                nums1[i][1] += nums2[idx][1]; idx++;
            }
            ad[0] = nums1[i][0]; ad[1] = nums1[i][1];
            ans.push_back(ad);
        }
        while(idx < nums2.size()){
            ad[0] = nums2[idx][0]; ad[1] = nums2[idx][1];
            ans.push_back(ad);
            idx++;
        }
        return ans;
    }
};